// https://leetcode.com/problems/3sum-with-multiplicity

class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target)  {
      int ct=0, mod=1e9+7;
      sort(nums.begin(), nums.end()); 

      for(int i=0; i<nums.size()-2; i++) {
        int start=i+1, end=nums.size()-1;
        while(start<end) {
          if(nums[start] + nums[end] + nums[i] == target) {
            long ctl=1, cth=1;
            while (start<end && nums[start]==nums[start+1]) {ctl++; start++;}
            while (start<end && nums[end]==nums[end-1]) {cth++; end--;}
            if(start==end) ct=(ct+ctl*(ctl-1)/2)%mod;
            else ct=(ct+ctl*cth)%mod;
            start++;end--;
          } else if (nums[start] + nums[end] + nums[i] > target) {
            end--;
          } else {
            start++;
          }
        }
      }
      return ct;
        
    }
};