// https://leetcode.com/problems/minimum-score-triangulation-of-polygon

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
      int n=values.size();

      vector<vector<int>> dp(n,vector<int> (n,INT_MAX));

      for(int l=2;l<n;l++) {
        for(int s=0;s<n-l;s++) {
          int e=s+l;
          for(int k=s+1;k<e;k++) {
            int prev = s+1==k? 0: dp[s][k];
            int next = k+1==e? 0: dp[k][e];
            dp[s][e] = min(dp[s][e], prev + (values[s] * values[e] * values[k]) + next);
          }
        }
      }
      return dp[0][n-1];
    }
};