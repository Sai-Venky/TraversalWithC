// https://leetcode.com/problems/largest-plus-sign

/*
    Traverse from left to right. Then from right to left.
    Then from top to bottom. Then from bottom to right.
    Find the minimum number of ones in all those directions.
    Take minimum of them all.
*/

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
      vector<vector<int>> dp(n, vector<int>(n, n));
      for (auto& m : mines) {
        dp[m[0]][m[1]] = 0;
      }
      
      for(int i=0;i<n;i++) {
        int l=0;
        for(int j=0;j<n;j++){
          l = dp[i][j] == 0 ? 0: l+1;
          dp[i][j] = min(dp[i][j], l);
        }
        int r=0;
        for(int j=n-1;j>=0;j--){
          r = dp[i][j] == 0 ? 0: r+1;
          dp[i][j] = min(dp[i][j], r);
        }
      }
      
      for(int j=0;j<n;j++) {
        int d=0;
        for(int i=0;i<n;i++){
          d = dp[i][j] == 0 ? 0: d+1;
          dp[i][j] = min(dp[i][j], d);
        }
        int u=0;
        for(int i=n-1;i>=0;i--){
          u = dp[i][j] == 0 ? 0: u+1;
          dp[i][j] = min(dp[i][j], u);
        }
      }
      
      
      int res=0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res = max(res, dp[i][j]);
        }
      }
      return res;
    }
};