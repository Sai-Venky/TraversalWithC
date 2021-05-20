// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

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
    int sum=0; 
    void findSum(TreeNode* root, TreeNode* p, TreeNode* gp) {
      
      if(root==NULL) return;
      
      if(gp!=NULL && gp->val%2 == 0) {
        sum+=root->val;
      }
      gp=p;
      p=root;
      findSum(root->left, p, gp);
      findSum(root->right, p, gp);
      
    }
  
    int sumEvenGrandparent(TreeNode* root) {
      findSum(root, NULL, NULL);
      return sum;
    }
};