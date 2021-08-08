// https://leetcode.com/problems/count-good-nodes-in-binary-tree

/*
  Logic - SF
  Code - DFS
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