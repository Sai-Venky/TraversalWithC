// https://leetcode.com/problems/sum-of-left-leaves

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
  int sum=0;
public:
    void findLeftSum(TreeNode* root, bool isLeft) {
      if(isLeft && root->left == NULL && root->right==NULL) {
        sum+=root->val;
      } 
      if(root->left)  findLeftSum(root->left, true);
      if(root->right) findLeftSum(root->right, false);
    }
  
    int sumOfLeftLeaves(TreeNode* root) {
      if(root==NULL) return 0;
      findLeftSum(root, false);
      return sum;
    }
};