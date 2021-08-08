// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

/*  
  Logic - SF
  Code  - Sliding Window
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
      
      long int m=0, sum=0, j=0;
      for(int i=0;i<nums.size();i++) {
        sum+=nums[i];
        if((i-j+1) - sum > 1) {sum-=nums[j++];}
        m = max(m, i-j);
      }
      
      return m;
    }
};

