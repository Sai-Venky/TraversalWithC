// https://leetcode.com/problems/cousins-in-binary-tree

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
  bool isCousins(TreeNode* root, int x, int y, bool siblings = false, bool cousin = false) {
    queue<TreeNode*> q, q1;
    q.push(root);
    while (!q.empty() && !cousin) {
      while (!q.empty()) {
        auto n = q.front();
        q.pop();
        if (n == nullptr) siblings = false;
        else {
          if (n->val == x || n->val == y) {
            if (!cousin) cousin = siblings = true;
            else return !siblings;
          }
          q1.push(n->left), q1.push(n->right), q1.push(nullptr);
        }
      }
      swap(q, q1);
    }
    return false;
  }
 */
class Solution {
public:
    TreeNode* xParent = NULL, *yParent = NULL;
    int xDepth = -1, yDepth = -2;
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, NULL, x, y, 0);
        return xDepth == yDepth && xParent != yParent;
    }
    void dfs(TreeNode* root, TreeNode* parent, int x, int y, int depth) {
        if (root == NULL) return;
        if (x == root->val) {
            xParent = parent;
            xDepth = depth;
        } else if (y == root->val) {
            yParent = parent;
            yDepth = depth;
        } else {
            dfs(root->left, root, x, y, depth + 1);
            dfs(root->right, root, x, y, depth + 1);
        }
    }
};