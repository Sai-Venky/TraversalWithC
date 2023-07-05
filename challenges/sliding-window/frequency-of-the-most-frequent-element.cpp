// https://leetcode.com/problems/frequency-of-the-most-frequent-element

// Good Question on realising this is sliding window.

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
      sort(nums.begin(), nums.end());
      long int m=1;
      long int sum=0, j=0;
      for(int i=0;i<nums.size();i++) {
        sum+=nums[i];
        while(((i-j+1)*nums[i]) - sum > k) {sum-=nums[j++];}
        m = max(m, i-j+1);
        
      }
      
      return m;
    }
};