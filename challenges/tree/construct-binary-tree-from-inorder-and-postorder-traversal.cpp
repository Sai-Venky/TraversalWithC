// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

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
    int t;
    TreeNode* buildTheTree(vector<int>& inorder, vector<int>& postorder, int s, int e) {
      if(s>e || t<0) return NULL;
      TreeNode* root=new TreeNode(postorder[t]);
      int i;
      t--;
      for(i=s;i<=e;i++) {
        if(inorder[i] == root->val) break;
      }
      root->right = buildTheTree(inorder, postorder, i+1, e);
      root->left = buildTheTree(inorder, postorder, s, i-1);        
      return root;
    }
  
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      int n=postorder.size(); 
      t=n-1;
      return buildTheTree(inorder, postorder, 0, n-1);
    }
};