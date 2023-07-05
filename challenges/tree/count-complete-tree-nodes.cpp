// https://leetcode.com/problems/count-complete-tree-nodes
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
  Logic - SF. Note the use of leaf ndoe check and power
  Code - Recursion
 */

class Solution {
    int lastLevelCount = 0;
    int totalLevel = 0;

public:
    
    void countCompleteTreeNodes(TreeNode* root, int level) {
        if(root == NULL) {
            return;
        }
        
        if(level > totalLevel) totalLevel = level;
        
        if(root->left == NULL && root->right == NULL && level == totalLevel) {
            lastLevelCount ++;
            return;
        }
        
        countCompleteTreeNodes(root->left, level + 1);
        
        countCompleteTreeNodes(root->right, level + 1);
    }
    
    int countNodes(TreeNode* root) {
        
        countCompleteTreeNodes(root, 0);
        return pow(2, totalLevel) + lastLevelCount - 1 ;
    }
};

/*

Time analysis with this solution is actually very tricky. In the beginning, I thought if each node takes logN time, then it will be O(NlogN). On a second thought, however, if(hl==hr) return pow(2,hl)-1; makes sure on each level/depth of the tree, only one node can possibly trigger the recursion, therefore it becomes h (height of the tree=logN) + (h-1) + (h-2)...+1 = O(h^2) = O(logN*logN) . How beautiful is this!

class Solution {

public:

    int countNodes(TreeNode* root) {

        if(!root) return 0;

        int hl=0, hr=0;

        TreeNode *l=root, *r=root;

        while(l) {hl++;l=l->left;}

        while(r) {hr++;r=r->right;}

        if(hl==hr) return pow(2,hl)-1;

        return 1+countNodes(root->left)+countNodes(root->right);

    }

};*/