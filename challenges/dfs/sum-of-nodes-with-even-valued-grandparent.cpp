// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

/*
  Logic - DFS
  Code - SF
*/
class Solution {
public:
    int sum=0; 
    void findSum(TreeNode* root, TreeNode* p, TreeNode* gp) {
      
      if(root==NULL) return;
      
      if(gp!=NULL && gp->val%2 == 0) {
        sum+=root->val;
      }
      gp=p;
      p=root;
      findSum(root->left, p, gp);
      findSum(root->right, p, gp);
      
    }
  
    int sumEvenGrandparent(TreeNode* root) {
      findSum(root, NULL, NULL);
      return sum;
    }
};