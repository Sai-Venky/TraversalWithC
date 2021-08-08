// https://leetcode.com/problems/minimum-size-subarray-sum

/*
    class Solution {
        public:
            int minSubArrayLen(int s, vector<int>& nums) {
                int n = nums.size(), len = INT_MAX;
                vector<int> sums(n + 1, 0);
                for (int i = 1; i <= n; i++) {
                    sums[i] = sums[i - 1] + nums[i - 1];
                }
                for (int i = n; i >= 0 && sums[i] >= s; i--) {
                    int j = upper_bound(sums.begin(), sums.end(), sums[i] - s) - sums.begin();
                    len = min(len, i - j + 1);
                }
                return len == INT_MAX ? 0 : len;
            }
        };
*/

/*  
  Logic - SF. Note that here we are trying to increase the j to find a lesser min value
  Code  - Sliding Window
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int j=0, len=INT_MAX, sum=0;
        
      for(int i=0;i<nums.size();i++) {
        sum+=nums[i];
        while(sum>=target && j<=i) {
          len=min(len, i-j+1);
          sum-=nums[j++];
        }
      }
      
      return len==INT_MAX?0:len;
    }
};