// https://leetcode.com/problems/path-sum

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)return false;                                         
        sum=sum-root->val;                                             
        if(sum==0&&!root->left&&!root->right)return true;              
        return hasPathSum(root->left,sum)||hasPathSum(root->right,sum);
    }
};