// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long max=1;
    void findSum(TreeNode* root, int *sum) {
      if(root==NULL) return;
      *sum+=root->val;
      findSum(root->left, sum);
      findSum(root->right, sum);      
    }
  
    int findMaxProd(TreeNode* root, int  *totalSum) {
      if(root==NULL) return 0;

      int lsum=findMaxProd(root->left, totalSum);
      int rsum=findMaxProd(root->right, totalSum);    
      long sum = lsum + rsum + root->val;
      long prod = (sum) * (*totalSum - sum);
      if(max < prod) max = prod;
      return sum;
    }
  
    int maxProduct(TreeNode* root) {
      int totalsum=0, sum=0;
      findSum(root, &totalsum);
      findMaxProd(root, &totalsum);
      return max%1000000007;
    }
};