// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        if(n==1 || n==0) return 0;
        if(n==2) {
            if(prices[1] > prices[0]) return prices[1] - prices[0];
            else return 0;
        }
        
        int dp[n][2];
        dp[0][0] =  0;
        dp[0][1] = -prices[0];
        dp[1][0] = max(dp[0][0] + prices[1], dp[0][1]);
        dp[1][1] = max(-prices[1], dp[0][0]);
        
        for(int i=1; i<n; i++) {
            dp[i][0] = max(dp[i-1][1] + prices[i], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0] - prices[i], dp[i-1][1]);
        }
        return dp[n-1][0];
        
    }
};