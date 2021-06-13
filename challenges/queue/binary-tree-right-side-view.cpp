// https://leetcode.com/problems/binary-tree-right-side-view/


/*
class Solution {
public:
    void dfs(TreeNode* root, int lv, vector<int> &res){
        if(!root)   return;
        if(lv>=res.size()) res.push_back(root->val);
        dfs(root->right,lv+1,res);
        dfs(root->left,lv+1,res);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};

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
    vector<int> rightSideView(TreeNode* root) {
      vector<int> out;
      if(!root) return out;
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty()) {
          int size=q.size();
          TreeNode* node = NULL;
          for(int i=0;i<size;i++) {
            node = q.front();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            q.pop(); 
          }
        out.push_back(node->val);
          
      }    
       
      return out;
    }
};
