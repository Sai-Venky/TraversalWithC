// https://leetcode.com/problems/coin-change

/*
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      int n=coins.size();
      vector<vector<int>> dp(n+1, vector<int>(amount+1, INT_MAX));
      dp[0][0] = 0;
      
      for(int i=1;i<=n;i++) {
        dp[i][0] = 0;
        // cout<<"\n";
        for(int j=1;j<=amount;j++) {
          
          dp[i][j] = min(dp[i-1][j], (j>=coins[i-1] && dp[i][j-coins[i-1]] !=INT_MAX?1+dp[i][j-coins[i-1]]:INT_MAX));
          // cout<<dp[i][j]<<" ";
        }
      }
      return dp[n][amount]==INT_MAX?-1:dp[n][amount];
    }
};
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      int n=coins.size();
      vector<int> dp(amount+1, INT_MAX);
      dp[0] = 0;
      
      for(int i=1;i<=n;i++) {
        for(int j=1;j<=amount;j++) {
          
          dp[j] = min(dp[j], (j>=coins[i-1] && dp[j-coins[i-1]] !=INT_MAX?1+dp[j-coins[i-1]]:INT_MAX));
        }
      }
      return dp[amount]==INT_MAX?-1:dp[amount];
    }
};