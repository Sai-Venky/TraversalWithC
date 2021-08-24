// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/

/* 
    Logic - 2 pointers
    Code - SF
    O(n)
*/
class Solution {
public:
    int minPairSum(vector<int>& nums) {
      int l=0, h=nums.size()-1;
      sort(nums.begin(), nums.end());
      int pairSum=nums[h]-nums[l];
      while(l<h) {
        pairSum=max(pairSum, nums[l++]+nums[h--]);
      }
      return pairSum;
    }
};