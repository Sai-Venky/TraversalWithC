// https://leetcode.com/problems/find-bottom-left-tree-value

/*  
  Logic - BFS
  Code  - SF. Ensure root alone edge case in handled.
*/

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
      TreeNode *leftMost = NULL;

      queue<TreeNode*> q;
      q.push(root);
      while( !q.empty() ) {
          int levelSize = q.size();
          for(int level = 0; level < levelSize; level++ ) {
              TreeNode* node = q.front(); q.pop();
              if ( level == 0 ) leftMost = node;

              if (node->left) q.push(node->left);
              if (node->right) q.push(node->right);

          }
      }
      return leftMost->val;
    }
};