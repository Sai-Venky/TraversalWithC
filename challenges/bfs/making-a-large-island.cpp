// https://leetcode.com/problems/making-a-large-island

class Solution {
public:
      
    void dfs(vector<vector<int>>& grid, int r, int c, int color, int *ct) {
      if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != 1)
          return;

      grid[r][c] = color;
      *ct=*ct+1;
      dfs(grid, r + 1, c, color, ct);
      dfs(grid, r - 1, c, color, ct);
      dfs(grid, r, c + 1, color, ct);
      dfs(grid, r, c - 1, color, ct);
    }
  
    int largestIsland(vector<vector<int>>& grid) {
      int n=grid.size();
      unordered_map<int, int> m;
      int color=-1, ct=0;
      queue<pair<int, int>> q;
      vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
      int maxIsland = 1;

      for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
          if(grid[i][j] == 1) {
            dfs(grid, i, j, color, &ct);
            m[color]=ct;
            maxIsland = max(maxIsland,ct);
            color--; ct=0;
          } else if(grid[i][j] == 0){
            q.push({i, j});
          }
        }
      }
      
      if(q.empty()) return maxIsland;
      
      while(!q.empty()) {
        
        pair<int, int> p=q.front(); q.pop();
        unordered_set<int> s;
        int tmp=0;
        for(auto dir:dirs) {
          int r=dir[0]+p.first;
          int c=dir[1]+p.second;
          if(r>=0 && r<n && c>=0 && c<n && s.find(grid[r][c])==s.end()) {
            s.insert(grid[r][c]);
            tmp+=m[grid[r][c]];
          }
        }
        if(tmp+1>maxIsland) maxIsland=tmp+1;
        
        
      }
      return maxIsland;
    }
};