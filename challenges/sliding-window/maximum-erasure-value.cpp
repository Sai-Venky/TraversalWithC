// https://leetcode.com/problems/maximum-erasure-value

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
      int l=0,r=0;
      int maxi=0;
      int n=nums.size();
      int sum=0;
      map<int, int> m;
      while(r<n) {
        if(m[nums[r]]==0) {
          m[nums[r]]++;
          sum+=nums[r];
          r++;
        } else {
          m[nums[l]]--;
          sum-=nums[l];
          l++;
        }
        maxi=max(maxi, sum);
      }
      return maxi;
    }
};