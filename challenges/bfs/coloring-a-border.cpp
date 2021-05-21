// https://leetcode.com/problems/coloring-a-border/

/*
    class Solution {
        void dfs(vector<vector<int>>& grid, int r, int c, int color) {
            if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != color)
                return;

            grid[r][c] = INT_MAX;

            dfs(grid, r + 1, c, color);
            dfs(grid, r - 1, c, color);
            dfs(grid, r, c + 1, color);
            dfs(grid, r, c - 1, color);
        }
    public:
        vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
            int rows, cols;

            if((rows = grid.size()) == 0 || (cols = grid[0].size()) == 0)
                return {};

            vector<vector<int>> temp = grid;
            dfs(temp, r0, c0, grid[r0][c0]);

            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                    if(i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
                        if(temp[i][j] == INT_MAX)
                            grid[i][j] = color;
                    } else {
                        if((temp[i][j]) == INT_MAX and 
                        ((temp[i - 1][j] != INT_MAX) || (temp[i + 1][j] != INT_MAX) ||
                            (temp[i][j - 1] != INT_MAX) || (temp[i][j + 1] != INT_MAX)))
                            grid[i][j] = color;
                    }
                }
            }

            return grid;
        }
    };
*/
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
      
      queue<pair<int, int>> q;
      q.push(make_pair(r0, c0));
      int m = grid.size(), n = grid[0].size();
      int k = grid[r0][c0];
      vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
      vector<vector<int>> visited(m, vector<int>(n, 0));
      vector<pair<int, int>> pairs;
      while(!q.empty()) {
        int ns=q.size();
        
        for(int i=0;i<ns;i++) {
          
          pair<int, int> p=q.front();
          q.pop();
          if(visited[p.first][p.second] == 1) continue;
            visited[p.first][p.second] = 1;
          for(auto dir:dirs) {
            int x = p.first  + dir[0];
            int y = p.second + dir[1];
            if(x<0 || y<0 || x>m-1 || y>n-1) continue;
            if(grid[x][y]==k) {
              q.push(make_pair(x, y));
            }

            if(p.first==0 || p.second==0 || p.first==m-1 || p.second==n-1 || grid[x][y]!=k) {
              pairs.push_back(make_pair(p.first, p.second));
            }
            
          }
          
        }
        
      }
      
      for(auto p:pairs) grid[p.first][p.second] = color;
      
      return grid;
      
    }
};