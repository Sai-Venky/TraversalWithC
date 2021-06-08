// https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int houseRobber(vector<int>& nums, int start, int end) {
        vector<int> dp(nums.size(), 0);
        dp[start] = nums[start];
        dp[start+1] = max(nums[start], nums[start+1]);
        for (int i=start+2; i<=end; i++)
          dp[i] = max({nums[i] + dp[i-2], dp[i-1]});
        return dp[end];
    }
    
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        if (nums.size() == 3) return max({nums[0], nums[1], nums[2]});
        
        return max(houseRobber(nums, 0, nums.size()-2), houseRobber(nums, 1, nums.size()-1));
    }
};