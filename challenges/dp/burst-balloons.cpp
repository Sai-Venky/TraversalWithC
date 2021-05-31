// https://leetcode.com/problems/burst-balloons

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        vector<int> baloons;
        baloons.push_back(1);
        for(auto num:nums) {
            if(num > 0) baloons.push_back(num);
        }
        baloons.push_back(1);
        int size = baloons.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));
        
        for(int range = 1; range < size; range++) {
            for(int left = 1; left < size - range; left++) {
                int right = left + range - 1, maxCoins = 0;
                for(int k = left; k <= right; k++) {
                    int coins = baloons[left-1] * baloons[k] * baloons[right+1];
                    coins += dp[left][k-1] + dp[k+1][right];
                    if(coins > maxCoins) maxCoins = coins;
                }
                dp[left][right] = maxCoins;
            }
        }        
        
        return dp[1][size-2];
    }
};