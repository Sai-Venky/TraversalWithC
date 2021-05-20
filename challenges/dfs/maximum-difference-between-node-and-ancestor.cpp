// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

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
    int dist;
    void findMaxAncestorDiff(TreeNode* root, int max, int min) {
      
      if(!root) return;
      if(root->val > max) max =root->val;
      if(root->val < min) min =root->val;
      
      if( abs(max-min) > dist) dist =  abs(max-min);
      findMaxAncestorDiff(root->left, max, min);
      findMaxAncestorDiff(root->right, max, min);
      
    }
  
    int maxAncestorDiff(TreeNode* root) {
      dist=0;
      int max=root->val; 
      int min=root->val;
      findMaxAncestorDiff(root, max, min);
      return dist;
    }
};