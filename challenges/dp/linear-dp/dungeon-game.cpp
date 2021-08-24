// https://leetcode.com/problems/dungeon-game

// https://leetcode.com/problems/dungeon-game/discuss/745340/post-Dedicated-to-beginners-of-DP

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
      int m=dungeon.size(), n=dungeon[0].size();
      vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
      // IMP
      dp[m-1][n]=1;
      dp[m][n-1]=1;
      int ct=0,i,j;
      for(i=m-1;i>=0;i--) {
        for(j=n-1;j>=0;j--) {
          
          dp[i][j] = min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j];
          // IMP
          dp[i][j] = dp[i][j]<=0?1:dp[i][j];
        }
      }
      
      return dp[0][0];
      
    }
};