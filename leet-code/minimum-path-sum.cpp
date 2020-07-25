// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        vector<vector<int>> dp(grid);
        if(dp.size() == 0) {
            return 0;
        }
        
        for(int i=0; i<dp.size(); i++) {
            for(auto j=dp[i].begin(); j!=dp[i].end(); j++) {
                *j=0;
            }
        } 
        
        int i,j,top,left;
        
        for(i=0; i<dp.size(); i++) {
            for(j=0; j<dp[i].size(); j++) {
                
                if(i==0 && j==0)     {
                    dp[i][j] = grid[i][j];
                    continue;
                }             
               if(i==0) {
                   top = INT_MAX;
               } else {
                   top = dp[i-1][j] + grid[i][j];
               }
                
                if(j==0) {
                   left = INT_MAX;
               } else {
                   left = dp[i][j-1] + grid[i][j];
               }
                
                dp[i][j] = min(top, left);
            }
        }
  
        return dp[i-1][j-1];
    }
};