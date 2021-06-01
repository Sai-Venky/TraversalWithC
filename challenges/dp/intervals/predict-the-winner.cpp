// https://leetcode.com/problems/predict-the-winner

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
      int n=nums.size();
      if(n<3) return true;

      vector<vector<int>> dp(n,vector<int> (n,0));
      
      for(int i=2;i<n;i++) {
        dp[i-2][i] = nums[i-2] - nums[i-1] + nums[i];
      }
      for(int l=3;l<n;l++) {
        for(int s=0;s<n-l;s++) {
          int e=s+l;
          dp[s][e] = max(nums[s] - dp[s+1][e], nums[e] - dp[s][e-1]);
        }
      }
      return dp[0][n-1] >=0;
    }
};