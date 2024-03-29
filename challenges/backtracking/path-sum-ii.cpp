// https://leetcode.com/problems/path-sum-ii

/*  
  Logic - Backtracking
  Code  - SF
*/

class Solution {
public:
    vector<vector<int>> outputs;
    void wrapper(TreeNode* root, int targetSum, int sum, vector<int> &output) {
      if(root==NULL) return;
      output.push_back(root->val);
      sum+=root->val;
      findPathSum(root, targetSum, sum, output);
      sum-=root->val;
      output.pop_back();
    }
  
    void findPathSum(TreeNode* root, int targetSum, int sum, vector<int> &output) {
      
      if(sum==targetSum && !root->left && !root->right) {
        outputs.push_back(output);
      }
      wrapper(root->left, targetSum, sum, output);
      wrapper(root->right, targetSum, sum, output);
    }
  
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
      vector<int> output;
      if(root!=NULL)
      wrapper(root, targetSum, 0, output);
      return outputs;
    }
};