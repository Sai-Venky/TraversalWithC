// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree

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
    int ct=0;
    
    void findPseudoPalindromicPaths(TreeNode* root, int m) {
      if(!root) return;
    
      m ^= 1<<root->val;
      if(!root->left && !root->right) {
        if((m & (m-1)) == 0) ct++;
      }
      
      findPseudoPalindromicPaths(root->left, m);
      findPseudoPalindromicPaths(root->right, m);
    }
  
    int pseudoPalindromicPaths (TreeNode* root) {
      int m=0;
      findPseudoPalindromicPaths(root, m);
      return ct;
    }
};