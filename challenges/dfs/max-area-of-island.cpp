// https://leetcode.com/problems/max-area-of-island/

/*  
  Logic - DFS
  Code  - SF
*/

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j) {
      
      if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return 0;
      
      if(grid[i][j] != 1) return 0;
      grid[i][j] = 0;
      return 1 + dfs(grid, i+1, j) + dfs(grid, i-1, j) + dfs(grid, i, j+1) + dfs(grid, i, j-1);
    }
  
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int max=0;
      for(int i=0; i<grid.size(); i++) {
        for(int j=0; j<grid[i].size(); j++) {
          int ct = dfs(grid, i ,j);
          if(ct>max) max =ct;
        }
      }
      return max;
    }
};