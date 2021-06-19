// https://leetcode.com/problems/number-of-enclaves/

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j) {
      
      if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return;
      if(grid[i][j]!=1) return;
      
      grid[i][j] = -1;
      dfs(grid, i+1, j);
      dfs(grid, i-1, j);
      dfs(grid, i, j+1);
      dfs(grid, i, j-1);
    }
  
    int numEnclaves(vector<vector<int>>& grid) {
      
      for(int i=0; i<grid.size(); i++) {
        for(int j=0; j<grid[i].size(); j++) {
 				  if (i == 0 || j == 0 || i == grid.size()-1 || j == grid[i].size()-1)
          dfs(grid, i, j);
        }
      }
      int ct=0;
      for(int i=0; i<grid.size(); i++) {
        for(int j=0; j<grid[i].size(); j++) {
          if(grid[i][j] == 1) ct++;
        }
      }
      return ct;
    }
};