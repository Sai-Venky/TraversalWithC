// https://leetcode.com/problems/count-complete-tree-nodes
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
    int lastLevelCount = 0;
    int totalLevel = 0;

public:
    
    void countCompleteTreeNodes(TreeNode* root, int level) {
        if(root == NULL) {
            return;
        }
        
        if(level > totalLevel) totalLevel = level;
        
        if(root->left == NULL && root->right == NULL && level == totalLevel) {
            lastLevelCount ++;
            return;
        }
        
        countCompleteTreeNodes(root->left, level + 1);
        
        countCompleteTreeNodes(root->right, level + 1);
    }
    
    int countNodes(TreeNode* root) {
        
        countCompleteTreeNodes(root, 0);
        return pow(2, totalLevel) + lastLevelCount - 1 ;
    }
};