// https://leetcode.com/problems/binary-tree-level-order-traversal-ii

/*
    int depth(TreeNode *root) {
        if (!root) return 0;
        return max(depth(root->left),depth(root->right))+1;
    }

    void levelOrder(vector<vector<int>> &ans, TreeNode *node, int level) {
        if (!node) return;
        ans[level].push_back(node->val);
        levelOrder(ans,node->left,level-1);
        levelOrder(ans,node->right,level-1);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int d = depth(root);
        vector<vector<int>> ans(d,vector<int> {});
        levelOrder(ans,root,d-1);
        return ans;
    }
*/

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       queue<TreeNode*> q;
       vector<vector<int>> outputs;
       if(root==NULL) return outputs;
       q.push(root);
      
       while(!q.empty()) {
        vector<int> output;
        int size=q.size();
        for(int i=0;i<size;i++) {
          TreeNode* node = q.front();
          if(node->left) q.push(node->left);
          if(node->right) q.push(node->right);
          
          output.push_back(node->val);
          q.pop();
          
        }
        outputs.push_back(output);
      }
      
      return vector<vector<int>>(outputs.rbegin(), outputs.rend());
      
      
    }
};