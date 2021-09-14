// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/

// note use of BFS here

class Solution {
  public:
    struct Position {
      int row, col;
      Position (int row, int col) : row(row), col(col) {}
    };
  
    bool isValid(const int r, const int c, const int R, const int C) {
      return r >= 0 && r < R && c >= 0 && c < C;
    }
  
    int minCost(vector<vector<int>>& grid) {
      const int n = grid.size(), m = n ? grid[0].size() : 0;
      vector <vector <int>> dp(n, vector <int>(m, INT_MAX));
      dp[0][0] = 0;
      queue <Position> bfsQueue;
      bfsQueue.push({0, 0});
      int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};
      while (!bfsQueue.empty()) {
        auto& p = bfsQueue.front();
        for (int i = 0; i < 4; ++i) {
          int newR = p.row + dr[i], newC = p.col + dc[i];
          if (isValid(newR, newC, n, m) && dp[newR][newC] > dp[p.row][p.col] + (grid[p.row][p.col] != i + 1)) {
            dp[newR][newC] = dp[p.row][p.col] + (grid[p.row][p.col] != i + 1);
            bfsQueue.push({newR, newC});
          }
        }
        bfsQueue.pop();
      }
      return dp[n - 1][m - 1];
    }
};

/*
*/

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, m+n));
        dp[0][0] = 0;
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        pq.push({0, 0, 0});
        
        while(!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            int r = v[1], c = v[2];

            for(int k=0; k<4; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];
                int cost = 1;
                if(k+1 == grid[r][c]) cost = 0;
                if(nr >= 0 && nc >=0 && nr < m && nc < n && cost + v[0] < dp[nr][nc]) {
                    dp[nr][nc] = cost + v[0];
                    pq.push({dp[nr][nc], nr, nc});
                }    
            }
        }
            
        return dp[m-1][n-1];
    }

};