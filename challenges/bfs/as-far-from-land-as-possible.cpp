// https://leetcode.com/problems/as-far-from-land-as-possible/

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
      int n = grid.size();
      int m=0;
      queue<pair<int, int>> q;
      
      for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
          if(grid[i][j]==1) q.push(make_pair(i,j));
        }
      }
      
      vector<vector<int>> dirs{{-1,0},{0,1},{1,0},{0,-1}};
      while(!q.empty()) {
  
        int s = q.size();
        
        for(int i=0;i<s;i++) {
          
          pair<int,int> e = q.front();
          
          for(auto dir:dirs){
            
            int l = e.first+dir[0];
            int r = e.second+dir[1];
            
            if(l>=0 && r>=0 && l<n && r<n && grid[l][r]==0) {
              q.push(make_pair(l,r));
              grid[l][r] = grid[e.first][e.second] + 1;
              m=max(m, grid[l][r]);
            }
            
          }
          
          q.pop();
          
        }
      }
      
      return (m > 0 ? m-1 : -1);;
    }
};