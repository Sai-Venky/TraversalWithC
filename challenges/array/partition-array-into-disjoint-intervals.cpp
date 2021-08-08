// https://leetcode.com/problems/partition-array-into-disjoint-intervals

/*
    Logic -
    Parition into two subsets.
    Maintain the maximum value in the left and keep comparing the current with that.
    If the value is less then only update the maxi left, else keep left alone.
*/

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
      
      int len=0, j=1;
      int maxiLeft=nums[0], maxi=nums[0];
      while(j<nums.size()) {
        if(nums[j]<maxiLeft) {
          len=j;
          maxiLeft=maxi;
        }
        maxi=max(maxi, nums[j++]);
      }
      
      return len+1;
    }
};