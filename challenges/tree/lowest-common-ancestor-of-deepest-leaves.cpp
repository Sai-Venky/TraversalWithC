// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

class Solution {
public:
   TreeNode* lca;
    int deepest = 0;
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        helper(root, 0);
        return lca;
    }

    int helper(TreeNode* node, int depth) {
        deepest = max(deepest, depth);
        if (!node) {
            return depth;
        }
        int left = helper(node->left, depth + 1);
        int right = helper(node->right, depth + 1);
        if (left == deepest && right == deepest) {
            lca = node;
        }
        return max(left, right);
    }
};