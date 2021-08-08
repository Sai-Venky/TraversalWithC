// https://leetcode.com/problems/regions-cut-by-slashes/

/*
  Logic - SF
  Code - DFS
*/

class Solution {
public:
    void dfs(vector<vector<int>>& fp, int i, int j) {
      
      if(i<0 || j<0 || i>=fp.size() || j>=fp.size() || fp[i][j]==1) return;
      
      fp[i][j]=1;
      dfs(fp, i+1, j);
      dfs(fp, i, j+1);
      dfs(fp, i-1, j);
      dfs(fp, i, j-1);
    }
  
    int regionsBySlashes(vector<string>& grid) {
      int n=grid.size();
      vector<vector<int>> fp(n*3, vector<int>(n*3, 0));
      
      for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
        
          if(grid[i][j] == '/') {
            fp[i*3][j*3+2] = 1;
            fp[i*3+1][j*3+1] = 1;
            fp[i*3+2][j*3] = 1;
          } else if(grid[i][j] == '\\') {
            fp[i*3][j*3] = 1;
            fp[i*3+1][j*3+1] = 1;
            fp[i*3+2][j*3+2] = 1;
          }
          
        }
      }
      int ct=0;
      for(int i=0;i<n*3;i++) {
        for(int j=0;j<n*3;j++) {
          if(fp[i][j]==0)  {
            dfs(fp, i, j); ct++;
          }
        }
      }
      return ct;
    }
};