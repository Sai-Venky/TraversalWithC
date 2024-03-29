// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/

/*
    class Solution {
        unordered_map<TreeNode*, vector<TreeNode*>>mp;
        vector<TreeNode*>leaves;
        int ans = 0;
        
        void storeLeaves(TreeNode* root) {
            if (!root) return;
            storeLeaves(root->left);
            if (!root->left && !root->right)
                leaves.push_back(root);
            if (root->left) {
                mp[root].push_back(root->left);
                mp[root->left].push_back(root);
            }
            if (root->right) {
                mp[root].push_back(root->right);
                mp[root->right].push_back(root);
            }
            storeLeaves(root->right);
        }
        
        void bfs(TreeNode* v, int distance) {    
            queue<TreeNode*>q;
            q.push(v);
            int dist = 0;
            
            unordered_map<TreeNode*, bool>visited;
            
            while (!q.empty()) {
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    TreeNode* node = q.front();
                    q.pop();
                    if (visited[node]) continue;
                    if (node != v && !node->left && !node->right)
                        ans++;
                    visited[node] = true;
                    for (auto j = 0; j < mp[node].size(); j++)
                        q.push(mp[node][j]);
                }
                dist++;
                if (dist > distance) return;
            }
    }
    
    public:
        int countPairs(TreeNode* root, int distance) {
            if (!root) return 0;
            storeLeaves(root);
            for (int i = 0; i < leaves.size(); i++)
                bfs(leaves[i], distance);
            return ans/2;
        }
    };
*/

// Note the use of array here to store the distances and calculate.
class Solution {
public:
    int res=0;
    vector<int> helper(TreeNode* root,int distance)
    {
        if(root==NULL)
            return {};
        auto left=helper(root->left,distance);
        auto right=helper(root->right,distance);
        vector<int> ret;
        if(left.size()==0&&right.size()==0)
        { 
            ret.push_back(1);
            return ret;
        }
        for(int i=0;i<left.size();i++)
            for(int j=0;j<right.size();j++)
            {
                if(left[i]+right[j]<=distance)
                    res++;
            }
        for(auto x:left) {
          ret.push_back(x+1);          
        }
        for(auto x:right) {
            ret.push_back(x+1);          
        }
        return ret;
    }
    
    int countPairs(TreeNode* root, int distance) {
        helper(root,distance);
        return res;
    }
};