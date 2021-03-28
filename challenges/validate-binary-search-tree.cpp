// https://leetcode.com/problems/validate-binary-search-tree/

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
    TreeNode* prev;
    bool valid;
    bool isValidBST(TreeNode* root) {
      prev = NULL;
      valid = true;
      inorder(root);
      return valid;
    }
  
    void inorder(TreeNode* root) {
      if(root==NULL || valid == false) return;
      inorder(root->left);
      if(prev!=NULL && prev->val>=root->val) {
        valid = false;return;
      }
      prev = root;
      inorder(root->right);
    }
};