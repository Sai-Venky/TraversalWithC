// https://leetcode.com/problems/convert-bst-to-greater-tree

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
    void replaceTree(TreeNode* root, int *sum){
      if(!root) return;
      
      replaceTree(root->right, sum);
      root->val = *sum + root->val;
      *sum = root->val;
      replaceTree(root->left, sum);
    }
  
    TreeNode* convertBST(TreeNode* root) {
      int sum=0;
      replaceTree(root, &sum);
      return root;
    }
};