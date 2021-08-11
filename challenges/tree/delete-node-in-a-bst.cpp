// https://leetcode.com/problems/delete-node-in-a-bst

/*
   Note the use of recursion here to find and delete the node from the tree.
*/
class Solution {
public:
  
    TreeNode* findAndDeleteNode(TreeNode* root, int key) {
      if(root==NULL) return NULL;
      if(key<root->val) root->left=findAndDeleteNode(root->left, key);
      else if(key>root->val) root->right=findAndDeleteNode(root->right, key);
      else {
        if(!root->left && !root->right) return NULL;
        else if (!root->right) return root->left;
        else if (!root->left) return root->right;
        else {
          TreeNode* rgt=root->right;
          while(rgt->left!=NULL) rgt=rgt->left;
          root->val=rgt->val;
          root->right=findAndDeleteNode(root->right, root->val);
        }
      }
      return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
      return findAndDeleteNode(root, key);
    }
};