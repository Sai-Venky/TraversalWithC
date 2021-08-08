// https://leetcode.com/problems/distribute-coins-in-binary-tree

/**
 https://leetcode.com/problems/distribute-coins-in-binary-tree/discuss/221939/C%2B%2B-with-picture-post-order-traversal
 */
class Solution {
public:
    int traverse(TreeNode* r, int &moves) {
      if (r == nullptr) return 0;
      int left = traverse(r->left, moves), right = traverse(r->right, moves);
      moves += abs(left) + abs(right);
      return r->val + left + right - 1;
    }
    int distributeCoins(TreeNode* r, int moves = 0) {
      traverse(r, moves);
      return moves;
    }
};