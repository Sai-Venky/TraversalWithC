// https://leetcode.com/problems/where-will-the-ball-fall/

/*
  We drop the ball at grid[0][i]
  and track ball position i1, which initlized as i.

  An observation is that,
  if the ball wants to move from i1 to i2,
  we must have the board direction grid[j][i1] == grid[j][i2]
  
   vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            int i1 = i, i2;
            for (int j = 0; j < m; ++j) {
                i2 = i1 + grid[j][i1];
                if (i2 < 0 || i2 >= n || grid[j][i2] != grid[j][i1]) {
                    i1 = -1;
                    break;
                }
                i1 = i2;
            }
            res.push_back(i1);
        }
        return res;
    }

    */

// Note how the cases are handled here.
class Solution {
public: 
    
    void dfs(vector<vector<int>>& grid, int i, int j, vector<int>& out) {
      
      if(j<0 || j>=grid[0].size()) {
        out.push_back(-1);
        return;
      } else if(i==grid.size()) {
        out.push_back(j);
        return;
      }
            
      if(grid[i][j]==1 && j+1<grid[0].size() && grid[i][j+1]==1) dfs(grid, i+1, j+1, out);
      else if(grid[i][j]==-1 && j-1>=0 && grid[i][j-1]==-1) dfs(grid, i+1, j-1, out);   
      else out.push_back(-1);
    }
  
    vector<int> findBall(vector<vector<int>>& grid) {
      vector<int> out;      
      for(int i=0;i<grid[0].size();i++) {
        dfs(grid, 0, i, out);
      }
      return out;
    }
};