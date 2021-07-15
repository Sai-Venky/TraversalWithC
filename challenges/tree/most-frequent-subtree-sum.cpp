// https://leetcode.com/problems/most-frequent-subtree-sum/

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
    unordered_map<int, int> m;
  
    int dfs(TreeNode* root) {
      if(root==NULL) return 0;
      int sum=root->val+dfs(root->left)+dfs(root->right);
      m[sum]++;
      return sum;
    }
  
    vector<int> findFrequentTreeSum(TreeNode* root) {
      vector<int> out;
      int maxi=0;
      int t = dfs(root);
      for(auto v:m) {
        if(v.second==maxi) {
          out.push_back(v.first);
        } else if(v.second>maxi) {
          out.clear();
          out.push_back(v.first);
          maxi=v.second;
        }
      }
      return out;
    }
};