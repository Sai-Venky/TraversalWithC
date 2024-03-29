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

// dervided from house robber1
class Solution {
public:
    int houseRobber(vector<int>& nums, int start, int end) {
      vector<int> dp(nums.size(), 0);
      int i=0;
      if(end-start+1 == 1) {
        return nums[start];
      } else if (end-start+1 == 2) {
        return max(nums[start], nums[start+1]);
      } else if (end-start+1 == 3) {
        return max(nums[start] + nums[start+2], nums[start+1]);
      }

      dp[start] = nums[start];
      dp[start+1] = nums[start+1];
      dp[start+2] = nums[start] + nums[start+2];
      // You wither rob the current house with 2 back, or rob prev with 3 back or skip 2 times and rob now.
      for(i=start+3;i<=end;i++) {
        dp[i] = max({nums[i] + dp[i-2], dp[i-1], dp[i-3] + nums[i]});
      }
      return dp[i-1];
    }
    
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        if (nums.size() == 3) return max({nums[0], nums[1], nums[2]});
        
        return max(houseRobber(nums, 0, nums.size()-2), houseRobber(nums, 1, nums.size()-1));
    }
};