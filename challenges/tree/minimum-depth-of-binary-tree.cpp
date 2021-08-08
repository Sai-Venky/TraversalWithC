// https://leetcode.com/problems/minimum-depth-of-binary-tree

/*
  Logic - SF
  Code - BFS Approach
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
      int hgt=0;
      if(root==NULL) return 0;
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty()) {
        int n=q.size();
        hgt++;
        for(int i=0;i<n;i++) {
          TreeNode* node=q.front();q.pop();
          if(node->left==NULL && node->right==NULL) return hgt;
          if(node->left) q.push(node->left);
          if(node->right) q.push(node->right);
        }
      }
      return hgt;
    }
};