// https://leetcode.com/problems/partition-equal-subset-sum/

/*
    class Solution {
    public:
        bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int num:nums) sum+=num;
        if(sum%2!=0) return false;
        sum=sum/2;
        
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        dp[0][0]=true;
        for(int i=1;i<=n;i++) dp[i][0]=true;
        
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=sum;j++) {
            
            dp[i][j] = dp[i-1][j] || (j-nums[i-1] >=0?dp[i-1][j-nums[i-1]]:false);
            }
        }
        return dp[n][sum];
        }
    };
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
      int n=nums.size();
      int sum=0;
      for(int num:nums) sum+=num;
      if(sum%2!=0) return false;
      sum=sum/2;
      
      vector<bool> dp(sum+1, false);
      dp[0]=true;
      
      for(int i=1;i<=n;i++) {
        //  Note it is in reverse. We are doing this, since doing in forward will return all as true as dp[0] is true 
        for(int j=sum; j >= nums[i-1]; j--)
            dp[j] = dp[j] || dp[j-nums[i-1]];
      }
      return dp[sum];
    }
};