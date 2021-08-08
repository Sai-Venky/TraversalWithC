// https://leetcode.com/problems/shortest-path-in-binary-matrix/

/*  
  Logic - BFS
  Code  - SF.
*/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      int n = grid.size();
      queue<pair<int, int>> q;
      if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
        return -1;
      q.push(make_pair(0,0));
      grid[0][0] = 1;
      vector<vector<int>> dirs{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,0},{1,1},{1,-1}};
      while(!q.empty()) {

        int s = q.size();
        
        for(int i=0;i<s;i++) {
          
          pair<int,int> e = q.front();
          if(e.first == n-1 && e.second == n-1)
            return grid[e.first][e.second];
          
          for(auto dir:dirs){
            
            int l = e.first+dir[0];
            int r = e.second+dir[1];
            
            if(l>=0 && r>=0 && l<n && r<n && grid[l][r]==0) {
              q.push(make_pair(l,r));
              grid[l][r] = grid[e.first][e.second] + 1;
            }
            
          }
          
          q.pop();
          
        }
      }
      
      return -1;
    }
};