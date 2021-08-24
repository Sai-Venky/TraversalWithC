// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

/*
    Find Longest Increasing in every step and store it for computations later.
*/

class Solution {
public:
    int findLongest(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, unsigned prev) {
      if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]>=prev) return 0;
      if(dp[i][j]==-1) { 
        dp[i][j] = max(dp[i][j], findLongest(matrix, dp, i, j+1, matrix[i][j]));
        dp[i][j] = max(dp[i][j], findLongest(matrix, dp, i, j-1, matrix[i][j]));
        dp[i][j] = max(dp[i][j], findLongest(matrix, dp, i+1, j, matrix[i][j]));
        dp[i][j] = max(dp[i][j], findLongest(matrix, dp, i-1, j, matrix[i][j]));
      }
      return 1+dp[i][j];
    }
  
    int longestIncreasingPath(vector<vector<int>>& matrix) {
      int m=matrix.size(), n=matrix[0].size(), out=0;
      vector<vector<int>> dp(m, vector<int>(n, -1));
      
      for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
          out=max(out, findLongest(matrix, dp, i, j, 2147483649));
        }
      }
        
      return out;
    }
};