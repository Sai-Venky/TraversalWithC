// https://leetcode.com/problems/find-largest-value-in-each-tree-row

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
    vector<int> largestValues(TreeNode* root) {
      
      vector<int> out;
      queue<TreeNode*> q;
      if(!root) return out;
      q.push(root);
      while( !q.empty() ) {
        int levelSize = q.size();
        int max=INT_MIN;
        for(int level = 0; level < levelSize; level++ ) {
            TreeNode* node = q.front(); q.pop();

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            if(node->val > max) max=node->val;
        }
        out.push_back(max);

      }
      return out;
    }
};