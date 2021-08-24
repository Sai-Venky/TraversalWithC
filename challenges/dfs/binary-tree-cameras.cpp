// https://leetcode.com/problems/binary-tree-cameras

// Note the use of logic here to install the cameras.

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 1) res++;
        return res;
    }
    
private:
    int res = 0;
    
    int dfs(TreeNode* root) {
        if (!root) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        if (left == 1 || right == 1) {
            res++;
            return -1;
        }
        
        else if (left == -1 || right == -1)
            return 0;
        
        else return 1;
    }
};