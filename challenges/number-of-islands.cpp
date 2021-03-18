// https://leetcode.com/problems/number-of-islands

class Solution {
    int m, n;
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        
        if(i<0 || j <0 || i>=n || j>=m ) {
            return;
        }
        if(grid[i][j ] == '2' || grid[i][j ] == '0') {
            return;
        }
        
        grid[i][j] = '2';
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int count = 0;        
        n = grid.size();
        m = grid[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1') {
                  count++;
                    dfs(grid, i, j);
                }
            }
        }
        
        
        
        return count;
    }
};