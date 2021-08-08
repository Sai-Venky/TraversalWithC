// https://leetcode.com/problems/check-completeness-of-a-binary-tree

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

   /*
  Logic - SF
  Code - Recursion
 */
 
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
      queue<TreeNode*> q;
      bool value = false;
      q.push(root);
      while(!q.empty()) {
        TreeNode *p = q.front();
        q.pop();
        if(p==NULL) {
                value=true;
        } else {
            if(value)
                return false;
            q.push(p->left);
            q.push(p->right);
        }
      }
      return true;
    }
};