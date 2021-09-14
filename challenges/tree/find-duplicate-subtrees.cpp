// https://leetcode.com/problems/find-duplicate-subtrees

// Note the use of string here to store the node values and POSTORDER alone works not inorder as in case of symmetric trees
// 

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
    unordered_map<string, vector<TreeNode*>> m;
  
    string dfs(TreeNode* root) {
      if(!root) return "$";
      string out=to_string(root->val) + "-" + dfs(root->left) + "-" + dfs(root->right);
      m[out].push_back(root);
      return out;
    }
  
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
      vector<TreeNode*> out;
      dfs(root);
      
      for(auto v:m) {
        if(v.second.size()>1) {
          out.push_back(v.second[0]);
        }
      }
      return out;
    }
};
$-0-$-0-$-0-$-0-$-0-$ 1
$-0-$-0-$ 2
$-0-$ 2
