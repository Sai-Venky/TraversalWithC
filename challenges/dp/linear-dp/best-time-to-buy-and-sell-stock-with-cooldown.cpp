// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75931/Easiest-JAVA-solution-with-explanations

/*
Define Recursion

buy[i]: To make a decision whether to buy at i, we either take a rest, by just using the old decision at i - 1, or sell at/before i - 2, then buy at i, We cannot sell at i - 1, then buy at i, because of cooldown.
sell[i]: To make a decision whether to sell at i, we either take a rest, by just using the old decision at i - 1, or buy at/before i - 1, then sell at i.
So we get the following formula:

sell[i] = Math.max(sell[i - 1], buy[i - 1] + prices[i]);
buy[i] = Math.max(buy[i - 1], sell[i - 2] - prices[i]);   
*/

class Solution {
public:
	int maxProfit(vector<int>& prices){
	
        int n = prices.size();
        if(n==1 || n==0) return 0;
        if(n==2) {
            if(prices[1] > prices[0]) return prices[1] - prices[0];
            else return 0;
        }
        int dp[n][2];
        dp[0][0] = 0; 
        dp[0][1] = - prices[0]; 
        dp[1][0] = max(dp[0][0],  dp[0][1] + prices[1]);
        dp[1][1] = max(dp[0][1],  -prices[1]);  
        
        for(int i=2; i<n; i++) {
            dp[i][0] = max(dp[i-1][0],  dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
        }
        
        return dp[n-1][0];
    }
};

int maxProfit(int[] prices) {
    if(prices == null || prices.length <= 1) return 0;
  
    int b0 = -prices[0], b1 = b0;
    int s0 = 0, s1 = 0, s2 = 0;
 
    for(int i = 1; i < prices.length; i++) {
    	b0 = Math.max(b1, s2 - prices[i]);
    	s0 = Math.max(s1, b1 + prices[i]);
    	b1 = b0; s2 = s1; s1 = s0; 
    }
    return s0;
}