// https://leetcode.com/problems/integer-break

class Solution {
public:
    int integerBreak(int n) {
      vector<int> dp(n+1, 0);
      dp[1]=1;
      dp[2]=1;
      for(int i=3;i<=n;i++) {
        for(int j=1;j<i;j++) {
          dp[i] = max({dp[i], max(dp[j], j) * max(dp[i-j], i-j)}) ;
        }
      }
      
      return dp[n];
    }
};