// https://leetcode.com/problems/minimum-falling-path-sum/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
      
      int m=matrix.size(), n=matrix[0].size(), mi=INT_MAX;
      vector<vector<int>> dp(m+1, vector<int>(n+2, INT_MAX));
      for(int i=0;i<n+1;i++) dp[0][i]=0;
      
      for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
          dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]}) + matrix[i-1][j-1];
        }
      }
      
      for(int i=1;i<n+1;i++){
        if(mi>dp[m][i]) mi=dp[m][i];
      }
      return mi;
    }
};