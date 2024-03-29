// https://leetcode.com/problems/find-eventual-safe-states

/*
  Logic - DFS. Note the use of colors here to mark the nodes to ensure we track if its visited again.
  Code - SF
*/

enum Color {WHITE, GRAY, BLACK};
class Solution {
public:
    bool dfs(int i, vector<int> & color, vector<vector<int>> & graph)
    {
        if(color[i]) return color[i] == BLACK;
        color[i] = GRAY;
        for(int & v : graph[i])
            if(!dfs(v, color, graph)) return false;
        color[i] = BLACK;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        int n = int(graph.size());
        vector<int> color(n, WHITE);
        vector<int> result;
        for(int i = 0; i < n; ++i)
            if(dfs(i, color, graph)) result.push_back(i);
        return result;
    }
};