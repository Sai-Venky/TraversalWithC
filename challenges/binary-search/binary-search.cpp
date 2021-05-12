// https://leetcode.com/problems/binary-search

class Solution {
public:
    int search(vector<int>& nums, int target) {
      int find=-1;
      int low=0, high=nums.size()-1;
      while(low<=high) {
        
        int mid = low + (high-low)/2;
        if(nums[mid] == target) {
          find=mid;
          break;
        } else if(nums[mid]<target) {
          low=mid+1;
        } else {
          high=mid-1;
        }
        
      }
      return find;
    }
};