// https://leetcode.com/problems/maximum-width-of-binary-tree/

// Note the use of 2*numbers to expand the width
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
    int widthOfBinaryTree(TreeNode* root) {
      int width=1;
      queue<pair<TreeNode*, unsigned long long>> q;
      q.push({root, 0});  

      while (!q.empty()) {
        int levelQueueSize = q.size(), min=q.front().second;
        unsigned long long max=q.front().second;  
        for (int i = 0; i < levelQueueSize; i++) {
          pair<TreeNode*, int> p = q.front(); q.pop();
          max = p.second;
          if (p.first->left) q.push({p.first->left, max*2});
          if (p.first->right) q.push({p.first->right, max*2+1});
        }
        if(max-min+1>width) width=1+max-min;
      }
      
      return width;
    }
};