// https://leetcode.com/problems/matrix-block-sum

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
      int m=mat.size(), n=mat[0].size();
      vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
      vector<vector<int>> out(m, vector<int>(n, 0));
      
      for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
          dp[i][j] = -dp[i-1][j-1] + dp[i-1][j] + dp[i][j-1] + mat[i-1][j-1];
        }
      }
        /*
        1  3   6
        5  12  21
        12 27  45

      */
      
      for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
          int li = max(i-k-1, 0);
          int lj = max(j-k-1, 0);
          int ri = min(i+k, m);
          int rj = min(j+k, n);
          out[i-1][j-1] = dp[ri][rj] + dp[li][lj] - dp[li][rj] - dp[ri][lj] ;
        }
      }
      
      return out;
    }
};

