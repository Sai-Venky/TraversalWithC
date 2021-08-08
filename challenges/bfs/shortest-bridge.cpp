// https://leetcode.com/problems/shortest-bridge/

/*

    Logic - BFS
      COmbination of DFS + BFS
      First find first 1 island and mark all as visited. Then increment and find next island.
    Code  - Traversing from right to left in the assignment.
*/

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
      int m=grid.size(), n=grid[0].size();
      queue<pair<int,int>> q;

      for(int i=0;i<m && q.empty();i++) {
        for(int j=0;j<n && q.empty();j++) {
          if(grid[i][j]) dfs(grid, i, j, q);
        }
      }
      int ct=0;
      vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};

      while(!q.empty()) {
        int sz=q.size();
        
        for(int k=0; k<sz; k++) {
          pair<int, int> p = q.front();
          for(auto dir:dirs) {
            int i = dir[0] + p.first;
            int j = dir[1] + p.second;
            if(i>=0 && i<m && j>=0 && j<n) {
              if(grid[i][j] == 1) return ct;
              else if(grid[i][j]==0) {
                grid[i][j] = -1;
                q.push(make_pair(i, j));
              }
            }
          }
          
          q.pop();
          
        }
        ct++;
      }
      
      return 0;
    }
  
    void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int,int>>& q) {
      int m=grid.size(), n=grid[0].size();
      if(i<0 || j<0 || i>=m || j >=n || grid[i][j] != 1 ) return;
      grid[i][j] = -1;
      q.push(make_pair(i,j));
      dfs(grid, i+1, j, q);    
      dfs(grid, i-1, j, q);    
      dfs(grid, i, j+1, q);    
      dfs(grid, i, j-1, q);    
    }
};