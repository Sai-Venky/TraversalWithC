// https://leetcode.com/problems/kth-smallest-element-in-a-bst

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
  int small, count;
  bool done;
public:
  
    void inorder(TreeNode* root) {
      if(root==NULL || done == 1) {
        return;
      }
      inorder(root->left);
      count++;
      if(count == small && done !=1) {
        done = true;
        small = root->val;
      }
      inorder(root->right);
      
    }
    int kthSmallest(TreeNode* root, int k) {
      small = k;
      count = 0;
      done = false;
      inorder(root);
      return small;
    }
};
