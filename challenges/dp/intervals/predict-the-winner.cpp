// https://leetcode.com/problems/predict-the-winner

/*
  Intuition - If player 1 picks the number i from [i, j], then effective score player 1 gets is nums[i] - dp[i+1, j].
  Note that cumulative scores can be negative also.
*/

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
      int n=nums.size();
      if(n<3) return true;

      vector<vector<int>> dp(n,vector<int> (n,0));
      
      // Player one has to take 2. hence +2 here
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