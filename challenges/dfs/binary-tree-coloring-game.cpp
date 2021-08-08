// https://leetcode.com/problems/binary-tree-coloring-game

/*
  Logic -
    Count the number of nodes in all directions.
    Note the subtraction part.
  Code -
    SF
*/

class Solution {
public:
    bool canWin=false;
    int traverse(TreeNode* root, int *x, int *n) {
      
      if(root==NULL) return 0;
      int l=traverse(root->left, x, n);
      int r=traverse(root->right, x, n);
      
      if(root->val == *x) {
        int t=*n-(l+r+1);
        if ( l>r+t || r>l+t || t>l+r) canWin=true;
      }
      return 1+l+r;
    }
  
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
      traverse(root, &x, &n);
      return canWin;
    }
};