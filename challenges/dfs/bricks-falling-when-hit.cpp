// https://leetcode.com/problems/bricks-falling-when-hit

/*
    Note this tough question in DFS https://leetcode.com/problems/bricks-falling-when-hit/discuss/119829/Python-Solution-by-reversely-adding-hits-bricks-back
    https://leetcode.com/problems/bricks-falling-when-hit/discuss/122758/Tricky-problem-that-reverses-LC305
    1. First we mark all the connected components as it is without this extra hits.
    2. Next we include those and try to find the components not already marked but will be marked now. 
       Reason is these are the components which would have fallen had this hit been removed.
       Also consider the edge case when that hit is connected by two ceilings.
       Consider this edge case also  - 
       [[1],[1],[1],[1],[1]]
       [[3,0],[4,0],[1,0],[2,0],[0,0]]
       reason for Recount condition 1: attached to ceiling directly.
       reason for reverse way of approaching hits: to ensure that above cases work [[3,0],[0,0]] or [[0,0],[3,0]]
    Union Find Expl - https://leetcode.com/problems/bricks-falling-when-hit/discuss/1391613/C%2B%2B-DSU-Code-and-Explaination

*/

class Solution {
    const vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    static constexpr int CEILING_ROW = 0;
    
    int dfs(vector<vector<int>>& grid, const int row, const int col)
    {
        // Return num bricks attached to ceiling.
        // Also floodfill to mark cells connected to ceiling already "2"
        
        // base
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
            return 0;        
        if (grid[row][col] != 1)
            return 0;
        
        grid[row][col] = 2; // 2 means brick in a cluster connected to ceiling  
        int ans = 1;        // At least this brick. 
        for (const auto [dx, dy] : directions)
            ans += dfs(grid, row+dx, col + dy);
        
        return ans;
    }
    
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) 
    {
        // Instead of we count fallen ones after each cut, we reverse the process by first removing all the hits. 
        // Count how many connected components from ceiling (no need to worry about bricks getting hold up by other ceiling-connected ones)
        // and find the difference each time we add back a brick which was hit.
        
        // First remove brick according to hits
        for (const auto & hit : hits)
            grid[hit[0]][hit[1]] = grid[hit[0]][hit[1]]? 0: -1; // -1 means hitting a blank spot. 
        
        vector<int> ans(hits.size(), 0); 
        
        // Initial condition after all hit ones removed.
        for (int col = 0; col < grid[0].size(); ++col)
            dfs(grid, CEILING_ROW, col);
        
        for (int i = hits.size() -1; i >=0; --i)
        {
            const int row = hits[i][0], col = hits[i][1];

            // everytime we add a brick, we probe if
            //  - it's attached to a ceiling-connected cluster, by checking its 4 neighbors
            //  - or it's directly attached to ceiling.
            // if either, we have to perform DFS again to recount how many bricks can be connected to ceiling. 
            int & hit_spot = grid[row][col];
            if (hit_spot == -1)
                // ignore as it was an empty spot.
                continue;
            
            hit_spot = 1;
            
            // Recount condition 1: attached to ceiling directly.
            bool needs_to_recount = (row == CEILING_ROW);            
            if (!needs_to_recount)
            {
                for (const auto [dx, dy] : directions)
                {
                    if (row + dx  < 0 || col + dy < 0 || row + dx >= grid.size() || col + dy >= grid[0].size())
                        continue;
                                        
                    if (grid[row+dx][col+dy] == 2)
                        // Recount condition 2: one neighbor can reach ceiling.
                        needs_to_recount = true;
                }
            }
            
            if (needs_to_recount)
                ans[i] = dfs(grid, row, col) - 1; // Exclude the newly added back one. 
        }
        
        return ans;        
    }
};