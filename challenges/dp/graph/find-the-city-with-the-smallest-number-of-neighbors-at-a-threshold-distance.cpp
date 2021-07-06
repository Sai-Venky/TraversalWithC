// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dT) {
      vector<vector<int>> dp(n, vector<int>(n, 10001));
      for(auto e:edges) {
        dp[e[0]][e[1]] = dp[e[1]][e[0]] = e[2];
      }
      
      for(int i=0;i<n;i++) dp[i][i]=0;
      
      
      for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
          for (int j = 0; j < n; ++j)
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      
      int m=INT_MAX, index=n;
      for(int i=n-1;i>=0;i--) {
        int count=0;
        for(int j=0;j<n;j++)
          if(dp[i][j]<=dT) count++;
        if(count<m) {
          m=count;
          index=i;
        }
      }
      return index;
    }
};
