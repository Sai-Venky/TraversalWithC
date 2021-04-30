// https://leetcode.com/problems/range-sum-of-bst

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
  int sum=0;
    int rangeSumBST(TreeNode* root, int low, int high) {
      sumBST(root, low, high);
      return sum;
    }
      
    void sumBST(TreeNode* root, int &low, int &high) {
      if(root==NULL) return;
      rangeSumBST(root->left, low, high);
      rangeSumBST(root->right, low, high);
      if(low <= root->val && root->val <= high) sum +=root->val;
    }
};