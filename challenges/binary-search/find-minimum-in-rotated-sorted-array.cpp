// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums){
      int low=0, high=nums.size()-1;
      int e = high;
      while(low<=high) {
        
        int mid = low + (high-low)/2;
        if(nums[mid] > nums[e]) {
          low=mid+1;
        } else {
          high=mid-1;
        }
        
      }
      return nums[low];
    }
};