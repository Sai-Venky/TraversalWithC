// https://leetcode.com/problems/rotting-oranges/

/*

  Keep note of the -1 in the initialization. This is the logical difference here to increment and calculate distance .
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      int m=grid.size(), n=grid[0].size();
      vector<vector<int>> dir = {{-1,0}, {1,0}, {0,1}, {0, -1}};   
      queue<pair<int,int>> q;
      
      for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
          if(grid[i][j] == 2) {
            grid[i][j] = 1;
            q.push({i, j});
          } else if(grid[i][j] == 1) {
            grid[i][j] = -1;
          }
        }
      }
      int ct=0;
      while(!q.empty()) {
        int l = q.size();
        for(int i=0; i<l; i++) {
          pair <int, int> pairval = q.front();
          for(auto val: dir) {
            int x = pairval.first + val[0]; 
            int y = pairval.second + val[1];
            if(x>=0 && y>=0 && x<m && y<n && grid[x][y] == -1) {
              q.push({x,y});
              grid[x][y] = grid[pairval.first][pairval.second]+1;
              ct = max(ct, grid[x][y]);
            }
          }
          q.pop();
        }
      }
      
      for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
          if(grid[i][j] == -1) {
            return -1;
          }
        }
      }
      
      return ct>0?ct-1:ct;
    }
};