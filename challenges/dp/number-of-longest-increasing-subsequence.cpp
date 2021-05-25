// https://leetcode.com/problems/number-of-longest-increasing-subsequence

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int maxlen = 1, ret = 0;
        vector<int> cnt(nums.size(), 1), dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp[j]+1 > dp[i]) dp[i] = dp[j]+1, cnt[i] = cnt[j];
                    else if (dp[i] == dp[j]+1) cnt[i] += cnt[j];
                }
            }
            maxlen = max(maxlen, dp[i]);
        }
        for (int i=0;i < dp.size();++i) 
            if (dp[i] == maxlen) ret += cnt[i];
        return ret;
    }
};