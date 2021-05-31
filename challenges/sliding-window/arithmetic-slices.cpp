// https://leetcode.com/problems/arithmetic-slices

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
      
      int n=nums.size();
      vector<int> diff(n, 0);
      int ct=0, l=0, r=1;
      for(int i=1;i<n;i++) {
        diff[i-1] = nums[i] - nums[i-1];

      }
      
      while(true) {
        if(l==n-1 || r==n-1) break;
        if(diff[r] == diff[l] && r-l+1>=2) ct+=(r-l);
        else l=r;
        r++;
        
      }
      return ct;
    }
};