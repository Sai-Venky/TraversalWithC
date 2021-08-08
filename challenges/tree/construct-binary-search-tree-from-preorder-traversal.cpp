// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
    TreeNode* constructTree(vector<int>& preorder, int s, int e) {
      if(s>e) return NULL;
      int ele = preorder[s], i=s;
      TreeNode* root = new TreeNode(ele);
      for(; i<=e; i++) {
        if(preorder[i]>ele) break;
      }
      root->left  = constructTree(preorder, s+1, i-1);
      root->right = constructTree(preorder, i, e);
      
      return root;
    }
  
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      
      return constructTree(preorder, 0, preorder.size()-1);
    }
};