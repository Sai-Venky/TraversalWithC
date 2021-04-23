// https://leetcode.com/problems/all-possible-full-binary-trees

class Solution {
public:
    unordered_map<int, vector<TreeNode*>> memo;
    
    vector<TreeNode*> allPossibleFBT(int N) 
    {
        if(memo.find(N) != memo.end()) return memo[N];
        if(N == 1) return memo[N] = {new TreeNode(0)};
        if(N%2 == 0) return {};
        
        vector<TreeNode*> tree;
        
        for(int x = 0 ; x < N ; ++x)
        {
            int y = N - x - 1;
            for(auto l: allPossibleFBT(x))
            {
                for(auto r: allPossibleFBT(y))
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    tree.push_back(root);
                }
            }
        }
        return memo[N] = tree;
    }
};