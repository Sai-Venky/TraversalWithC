// https://leetcode.com/problems/deepest-leaves-sum



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