// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal

class Solution {
    TreeNode* recoverFromPreorder(string &S, int &i, int d)
    {
        int j = S.find_first_of("0123456789", i); 
        if(j - i != d) return NULL;
        
        i = S.find("-", j);
        int val = stoi(S.substr(j, i - j));
        
        TreeNode* root=new TreeNode(val);
        root->left = recoverFromPreorder(S, i, d + 1);
        root->right = recoverFromPreorder(S, i, d + 1);
        return root;
    }
public:
    TreeNode* recoverFromPreorder(string S)
    {
        int i = 0;
        return recoverFromPreorder(S, i, 0);
    }
};