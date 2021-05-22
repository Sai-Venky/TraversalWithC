// https://leetcode.com/problems/out-of-boundary-paths

class Solution {
public:
    int mod = pow(10,9) + 7;
    int dfs(int m, int n, int moves, int i, int j, vector<vector<vector<int>>>& dp) {
      
      if(i<0 || j<0 || i>=m || j>=n) {return 1;}
      if(moves==0) return 0;
      if(dp[moves][i][j] != -1) return dp[moves][i][j]%mod;
      int count=0;
      count= (count+dfs(m, n, moves-1, i+1, j, dp))%mod;
      count= (count+dfs(m, n, moves-1, i-1, j, dp))%mod;
      count= (count+dfs(m, n, moves-1, i, j+1, dp))%mod;
      count= (count+dfs(m, n, moves-1, i, j-1, dp))%mod;
      dp[moves][i][j] = count;
      return dp[moves][i][j] % mod;
    }
  
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
      vector<vector<vector<int>>> dp(maxMove+1, vector<vector<int>>(m, vector<int>(n, -1)));
      int ct = dfs(m, n, maxMove, startRow, startColumn, dp);
      return ct;
    }
};