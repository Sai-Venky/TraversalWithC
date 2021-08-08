// https://leetcode.com/problems/search-in-rotated-sorted-array

/*
If the entire left part is monotonically increasing, which means the pivot point is on the right part
If left <= target < mid ------> drop the right half
Else ------> drop the left half
If the entire right part is monotonically increasing, which means the pivot point is on the left part
If mid < target <= right ------> drop the left half
Else ------> drop the right half
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
      int low=0, high=nums.size()-1;
      while(low<=high) {
        int mid = low + (high-low)/2;
        if(nums[mid]==target) {
          return mid;
        }
        if(nums[mid]>=nums[low]) {
          if(target>=nums[low] && target<nums[mid]) high=mid-1;
          else low=mid+1;
        } else {
          if(target<=nums[high] && target>nums[mid]) low=mid+1;
          else high=mid-1;
        }
        
      }
      return -1;
    }
};