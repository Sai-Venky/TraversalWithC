// https://leetcode.com/problems/stone-game/

class Solution {
public:
    bool stoneGame(vector<int>& nums)  {
      int n=nums.size();
      if(n<3) return true;

      vector<int> dp(n,0);
      
      for(int i=2;i<n;i++) {
        dp[i-2] = nums[i-2] - nums[i-1] + nums[i];
      }
      for(int l=3;l<n;l++) {
        for(int s=0;s<n-l;s++) {
          int e=s+l;
          dp[s] = max(nums[s] - dp[s], nums[e] - dp[s+1]);
        }
      }
      return dp[n-1] >=0;
    }
};