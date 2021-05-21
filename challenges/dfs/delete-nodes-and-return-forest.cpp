// https://leetcode.com/problems/delete-nodes-and-return-forest/

/*
    Starting from the bottom , nodes are deleted. 
    Why bottom? cause you dont need to worry about the top, but in reverse the deletion of top affects the bottom.
*/

class Solution {
    unordered_set<int> del;
    vector<TreeNode *> res;
    
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(const int &x: to_delete)    del.insert(x);
        
        dfs(root);
        if(root != nullptr && del.count(root->val) == 0)    res.emplace_back(root);
        return res;
    }
    
    void dfs(TreeNode *&root) {
        if(root == nullptr)     return;
        
        dfs(root->left);
        dfs(root->right);
        
        if(root != nullptr && del.count(root->val) == 1) {
            if(root->left != nullptr)   res.emplace_back(root->left);
            if(root->right != nullptr)  res.emplace_back(root->right);
            root = nullptr;
        }
    }
};