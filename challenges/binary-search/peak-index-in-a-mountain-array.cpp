// https://leetcode.com/problems/peak-index-in-a-mountain-array

/*
  Code - BS
  Logic - SF
*/
// Same as peak element

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
      int low=0, high=arr.size()-1;

      while(low<=high) {
        
        int mid = low + (high-low)/2;
        if(arr[mid] > arr[mid+1]) {
          high=mid-1;
        } else {
          low=mid+1;
        }
        
      }
      return low;
    }
};