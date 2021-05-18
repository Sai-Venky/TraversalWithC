// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
    int maxLevelSum(TreeNode* root) {
      
      queue<TreeNode*> q;
      int max=INT_MIN, level=0;
      int l=1;
      q.push(root);
      
      while(!q.empty()) {
        
        int size=q.size();
        int sum=0;
        for(int i=0;i<size;i++) {
          TreeNode* node = q.front();
          
          if(node->left) q.push(node->left);
          if(node->right) q.push(node->right);
          sum+=node->val;
          q.pop();
          
        }
        if(max<sum) {
          max=sum;
          level=l;
        }
        l++;
      }
      return level;
    }
};