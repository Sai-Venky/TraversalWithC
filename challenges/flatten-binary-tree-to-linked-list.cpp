// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

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
    TreeNode* prev=NULL;
    void flatten(TreeNode* root) {
      flattenHelper(root);
      TreeNode* next = NULL;
      while(prev) {
        TreeNode* temp = prev->right;
        prev->right = next;
        next=prev;
        prev=temp;
      }
    }
  
    void flattenHelper(TreeNode* root) {
      if(root==NULL) return;
      TreeNode* l = root->left;
      TreeNode* r = root->right;
      root->left=NULL;
      root->right = prev;
      prev = root;
      flattenHelper(l);
      flattenHelper(r);
    }
};