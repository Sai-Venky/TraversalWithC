// https://leetcode.com/problems/longest-increasing-subsequence

// https://leetcode.com/problems/longest-increasing-subsequence/discuss/152065/Python-explain-the-O(nlogn)-solution-step-by-step

class Solution {
public:
    int bs(vector<int>& dp, int l, int h, int num) {
      int m=0;
      while(l<=h){
        m = l + (h-l)/2;  
        if(dp[m] == num) {
            return m;
        } else if(dp[m] >= num) {
          h=m-1;
        } else {
          l=m+1;
        }
      }
      return l;
      
    }
  
    int lengthOfLIS(vector<int>& nums) {
      
      int n=nums.size();
      vector<int> dp(n);
      dp[0] = nums[0];
      int size=0;
      
      for(int i=0;i<n;i++) {

        if(nums[i] > dp[size]) {
            dp[++size] = nums[i];
        }
        else {
          int p = bs(dp, 0, size, nums[i]);
          dp[p] = nums[i];
        }

      }
      return size+1;
      
    }
};