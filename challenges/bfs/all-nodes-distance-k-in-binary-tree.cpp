// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

/*
    DFS+BFS
    DFS for finding the neighbours
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<TreeNode*>> m ;
      
    void dfs(TreeNode* root, TreeNode* parent) {
      if(!root) return;
      
      if(parent) m[root->val].push_back(parent);
      
      if(root->left) {
        m[root->val].push_back(root->left);
        dfs(root->left, root);
      }
      
      if(root->right) {
        m[root->val].push_back(root->right);  
        dfs(root->right, root);
      }
      
    }
  
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      
      dfs(root, NULL);
      unordered_map<int, bool> visited;
      vector<int> output;
      int l=0;
      queue<TreeNode*> q;
      q.push(target);
      visited[target->val] = true;
      if(l!=k)
      while(!q.empty()) {
        int size=q.size();
        for(int i=0;i<size;i++) {
          TreeNode* node = q.front();
          q.pop();
          visited[node->val] = true;
          for(auto neigh:m[node->val]) {
            if(!visited[neigh->val]) q.push(neigh);
          }
        }
        l++;
        if(l==k) break;
      }
      while(q.size()) {
        TreeNode* node = q.front();
        q.pop();
        output.push_back(node->val);
      }
      return output;
    }
};