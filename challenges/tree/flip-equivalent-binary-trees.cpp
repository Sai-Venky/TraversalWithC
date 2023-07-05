// https://leetcode.com/problems/flip-equivalent-binary-trees

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
    bool checkFlipEquivalent(TreeNode* root1, TreeNode* root2) {

        if( (!root1 && root2) || (!root2 && root1)) {
            return false;
        } else if(!root1 && !root2) {
            return true;
        }

        if((root1->left && root2->left && root1->left->val == root2->left->val) ||
        (root1->right && root2->right && root1->right->val == root2->right->val)) {
            return checkFlipEquivalent(root1->left, root2->left) &&
            checkFlipEquivalent(root1->right, root2->right);
        } else if((root1->left && root2->right && root1->left->val == root2->right->val) ||
        (root1->right && root2->left && root1->right->val == root2->left->val)) {
            return checkFlipEquivalent(root1->right, root2->left) &&
            checkFlipEquivalent(root1->left, root2->right);
        } else {
            if(!root1->left && !root2->left && !root1->right && !root2->right) {
                return true;
            }
            return false;
        }
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if( (!root1 && root2) || (!root2 && root1)) {
            return false;
        } else if(!root1 && !root2) {
            return true;
        }

        return root1->val == root2->val && checkFlipEquivalent(root1, root2);
    }
};