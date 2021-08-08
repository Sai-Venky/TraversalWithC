// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree


/* 
  Logic - DFS
  https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/discuss/648898/figure-illustrationC%2B%2B-DFS%2B-Odd-frequency-count-and-4-line-solution 
  Code  - Note the use of n & n-1 as bitmask

*/

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