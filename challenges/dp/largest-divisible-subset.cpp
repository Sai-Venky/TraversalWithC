// https://leetcode.com/problems/largest-divisible-subset/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
      
      int m=0, ct=1, n=nums.size();
      sort(nums.begin(), nums.end());
      vector<int> dp(n, 1);
      vector<int> out;
      for(int i=0;i<n;i++) {
        
        int l=0;
        while(l<i) {
          
          if(nums[i] % nums[l]==0) {
            dp[i] = max(dp[i], dp[l]+1);
          }
          l++;
        }
        if(dp[i]>ct) {
          ct=dp[i];
          m=i;
        }        
      }
      int temp=nums[m];
      for(int i=n-1;i>=0;i--) 
        if (temp%nums[i]==0 && dp[i] == ct) {
          temp=nums[i];
          ct--;
          out.push_back(nums[i]);
        }

      
      return out;
    }
};

