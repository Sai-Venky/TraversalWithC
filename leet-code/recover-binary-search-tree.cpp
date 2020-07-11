// https://leetcode.com/problems/recover-binary-search-tree

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
    int previousValue;
    TreeNode *previous;
    bool isBST = false;
public:

    void swapValue(TreeNode* first, TreeNode* second) {            
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
    
    void sortBST(TreeNode* root) {
        if(root == NULL) return;
        sortBST(root->left);   
        if(previous != NULL && root->val < previous->val) {
            swapValue(previous, root);            
        } else {
            previous = root;       
        }
        
        sortBST(root->right);
    }

    void bst(TreeNode* root) {
        if(root == NULL || isBST == false) return;
        
        int currentValue = root->val;
        bst(root->left);   

        if(currentValue < previousValue) {
            isBST = false;
            return;
        }
        previousValue = currentValue;

        bst(root->right);    
    }
    
    void recoverTree(TreeNode* root) {

        if(root!= NULL) {
            while(!isBST) {
                previous = NULL;
                sortBST(root);
                previousValue = INT_MIN;
                isBST = true;
                bst(root);                
            }        
        }
    }
};