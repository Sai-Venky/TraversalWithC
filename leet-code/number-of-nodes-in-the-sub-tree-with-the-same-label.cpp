// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label

class Solution {
public:
    void dfs(vector<vector<int>> &neighbours, int i, string &labels, vector<int> &count,int alphabetParent[]) {
            
        if(count[i]!=0) return;
        count[i] = 1;
        for(auto value: neighbours[i]) {
            int alphabetChild[26] = {};
            dfs(neighbours, value, labels, count, alphabetChild);
            for (auto k = 0; k < 26; ++k)
                alphabetParent[k] += alphabetChild[k]; 
        }
            
        count[i] = ++alphabetParent[labels[i] - 'a'];
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> neighbours(n);
        vector<int> count(n, 0);
        int alphabetParent[26] = {};

       for (auto &e : edges) {
            neighbours[e[0]].push_back(e[1]);
            neighbours[e[1]].push_back(e[0]);
        }
        dfs(neighbours, 0, labels, count, alphabetParent);
        return count;
    }
};