// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
      int i;
      if(nums.size() == 1) {
        return nums[0];
      } else if (nums.size() == 2) {
        return max(nums[0], nums[1]);
      } else if (nums.size() == 3) {
        return max(nums[0] + nums[2], nums[1]);
      }
      vector<int> dp(nums.size(), 0);
      dp[0] = nums[0];
      dp[1] = nums[1];
      dp[2] = nums[0] + nums[2];
      // You wither rob the current house with 2 back, or rob prev with 3 back or skip 2 times and rob now.
      for(i=3;i<nums.size();i++) {
        dp[i] = max({nums[i] + dp[i-2], dp[i-1], dp[i-3] + nums[i]});
      }
      
      return dp[i-1];
    }
};