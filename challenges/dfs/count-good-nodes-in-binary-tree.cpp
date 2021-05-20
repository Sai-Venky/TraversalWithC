// https://leetcode.com/problems/count-good-nodes-in-binary-tree

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
    void findGoodNodes(TreeNode* root, int val) {
      if(!root) return;
      if(root->val>=val) {
        val=root->val;
        ct++;
      }
      findGoodNodes(root->left, val);
      findGoodNodes(root->right, val);
    }
  
    int goodNodes(TreeNode* root) {
      findGoodNodes(root, root->val);
      return ct;
    }
};