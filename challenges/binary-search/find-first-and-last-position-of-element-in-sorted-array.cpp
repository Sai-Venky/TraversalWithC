// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      
      int l=0, h=nums.size()-1;
      int f=-1, la=-1;
      
      while(l<=h) {
        int m = l + (h-l)/2;
        if(nums[m]==target){
          h=m-1;
          f=m;
        } else if(nums[m]<target) {
          l=m+1;
        } else {
          h=m-1;
        }
      }
      l=0, h=nums.size()-1;
      while(l<=h) {
        int m = l + (h-l)/2;
        if(nums[m]==target){
          l=m+1;
          la=m;
        } else if(nums[m]<target) {
          l=m+1;
        } else {
          h=m-1;
        }
      }
      
      return vector<int>{f,la};
      
    }
};