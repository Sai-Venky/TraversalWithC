// https://leetcode.com/problems/deepest-leaves-sum

/*
  Logic - SF
  Code - DFS
*/
class Solution {
public:
    int maxdepth=0;
    int sum=0;
    void findDeepest(TreeNode* root, int depth) {
      if(root==NULL) return;
      if(depth>maxdepth) {
        maxdepth=depth;
        sum=0; sum+=root->val;
      } else if(depth==maxdepth) {
        sum+=root->val;
      }
      findDeepest(root->left, depth+1);
      findDeepest(root->right, depth+1);
    }
  
    int deepestLeavesSum(TreeNode* root) {
      findDeepest(root, 0);
      return sum;
    }
};