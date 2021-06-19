// https://leetcode.com/problems/cousins-in-binary-tree

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
  bool foundx, foundy;
  int parentx, parenty, depthx, depthy;

  
public:
    void checkIfCousins(TreeNode* root, int x, int y, int depth, TreeNode* parent) {
      if((foundx && foundy) || root==NULL) return;
      
      if(root->val==x){
        foundx = true;
        parentx = parent->val;
        depthx = depth;
      }
      if(root->val==y){
        foundy = true;
        parenty = parent->val;
        depthy = depth;
      }
      checkIfCousins(root->left, x, y, depth+1, root);
      checkIfCousins(root->right, x, y, depth+1, root);
    }
  
    bool isCousins(TreeNode* root, int x, int y) {
      if(root==NULL) return false;  
      parentx = root->val;
      parenty = root->val;
      foundx = false;
      foundy = false;
      TreeNode* temp = new TreeNode(0);
      checkIfCousins(root, x, y, 0, temp);
      if((foundx && foundy) && (parentx!=parenty) && (depthx == depthy)) {
        return true;
      }
      return false;
    }
};
