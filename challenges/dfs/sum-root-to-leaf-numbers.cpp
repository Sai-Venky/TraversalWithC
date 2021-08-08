// https://leetcode.com/problems/sum-root-to-leaf-numbers

/*
  Logic - DFS
  Code - SF
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