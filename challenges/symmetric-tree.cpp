// https://leetcode.com/problems/symmetric-tree/

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
    
    bool symmetric(TreeNode* sleft, TreeNode* sright) {
      if(sleft != NULL && sright != NULL) {
        if(sleft->val != sright->val) return false;
        return symmetric(sleft->right, sright->left) && symmetric(sleft->left, sright->right);
      } else if(sleft == NULL && sright == NULL) {
        return true;
      } else {
        return false;
      };
    }
  
    bool isSymmetric(TreeNode* root) {
        return symmetric(root->left, root->right);
    }
};