// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree

/*
  Logic - DFS
  Code - SF
*/

class Solution {
public:  
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(original == NULL) return NULL;
        if(original == target) return cloned;
        TreeNode* l = getTargetCopy(original->left, cloned->left, target);
        TreeNode* r = getTargetCopy(original->right, cloned->right, target);
        return (l!=NULL) ?  l :  r;
    }
};