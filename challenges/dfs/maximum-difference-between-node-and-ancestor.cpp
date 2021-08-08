// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

/*  
  Logic - DFS
  Code  - SF
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