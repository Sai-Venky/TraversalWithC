// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

class Solution {
    vector<int>parent;
    int find(int x) {
        return parent[x] == x ? x : find(parent[x]);
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        
        if (stones.empty()) return 0;
        
        int m = stones.size();
        
        parent.resize(m, 0);
        for (int i = 0; i < m; i++)
            parent[i] = i;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    int x = find(i);
                    int y = find(j);
                    if (x != y)
                        parent[y] = x;
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < m; i++) {
            if (parent[i] == i)
                ans++;
        }
        
        return m-ans;
    }
};