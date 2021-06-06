// https://leetcode.com/problems/coin-change-2/

/*
class Solution {
public:
    int change(int amount, vector<int>& coins) {
      int n=coins.size();
      vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
      dp[0][0] = 1;
      
      for(int i=1;i<=n;i++) {
        dp[i][0] = 1;
        for(int j=1;j<=amount;j++) {
          
          dp[i][j] = dp[i-1][j] + (j>=coins[i-1]?dp[i][j-coins[i-1]]:0);
        }
      }
      return dp[n][amount];
    }
};
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
      int n=coins.size();
      vector<int> dp(amount+1, 0);
      dp[0] = 1;
      
      for(int i=1;i<=n;i++) {
        for(int j=1;j<=amount;j++) {
          
          dp[j] = dp[j] + (j>=coins[i-1]?dp[j-coins[i-1]]:0);
        }
      }
      return dp[amount];
    }
};