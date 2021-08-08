// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/

// SF Logical

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
      
      int right=0, left=0, n=nums.size();
      for(int num:nums) right+=num;
      
      for(int i=0;i<n;i++) {
        right -= nums[i];
        left += nums[i];
        nums[i] = (((i+1)*nums[i])-left) + (right-((n-i-1)*nums[i]));
      }
      
      return nums;
    }
};