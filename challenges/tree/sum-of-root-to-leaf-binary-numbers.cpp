// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers

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
  Logic - SF.
  Code - Recursion
 */
class Solution {
public:
    int sum = 0;
        
    int decimalValue(vector<int> path) {
        int level = 0, decimalValue = 0;
        for (auto i = path.crbegin(); i != path.crend(); ++i, level++) {
            if(*i == 0)  continue;
            decimalValue += pow(2, level);
        }
        return decimalValue;
    }
    
    void sumRootToLeafs(TreeNode* root, vector<int> path) {
        if(root == NULL) return;
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL) {
            sum += decimalValue(path);
            return;
        }
        sumRootToLeafs(root->left, path);
        sumRootToLeafs(root->right, path);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        vector <int> path;
        sumRootToLeafs(root, path);
        return sum;
        
    }
};