// https://leetcode.com/problems/sum-root-to-leaf-numbers

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
  
    void dfs(TreeNode* root, int digit) {
          
      if(!root) return;
      digit = digit*10+root->val;
      if(!root->left && !root->right) sum+=digit;
      dfs(root->left, digit);
      dfs(root->right, digit);
    }
  
    int sumNumbers(TreeNode* root) {
      dfs(root, 0);
      return sum;
    }
};