// https://leetcode.com/problems/longest-arithmetic-subsequence

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
      int n=nums.size();
      vector<vector<int>> dp(n, vector<int>(2001,0));
      int ct=2;

      for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
          int d=nums[j]-nums[i]+500;
          dp[j][d]=dp[i][d]!=0?dp[i][d]+1:2;
          ct=max(ct, dp[j][d]);
        }
      }
      
      return ct;
    }
};