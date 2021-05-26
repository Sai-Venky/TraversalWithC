// https://leetcode.com/problems/delete-and-earn/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int n = nums.size();
        if (!n) return 0;
        
        sort(nums.begin(), nums.end());
        
        vector<int>dp(n);
        
        for (int i = 0; i < n; i++)
            dp[i] = nums[i];
        
        for (int i = 1; i < n; i++) {
            for (int j =  0; j < i; j++) {
                if (nums[j] != nums[i]-1)
                    dp[i] = max(dp[i], dp[j]+nums[i]);
            }
          cout<<dp[i]<<" ";

        }
        
        return *max_element(dp.begin(), dp.end());
    }
};