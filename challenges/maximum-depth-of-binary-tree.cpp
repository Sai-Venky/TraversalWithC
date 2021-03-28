// https://leetcode.com/problems/maximum-depth-of-binary-tree

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
    int height = 0;
    int maxDepth(TreeNode* root) {
        findMaxDepth(root, 1);
      return height;
    }
  
    void findMaxDepth(TreeNode* root, int level) {
      if(root==NULL) return;
      if(level>height) height = level;
      findMaxDepth(root->left, level+1);
      findMaxDepth(root->right, level+1);

    }
};