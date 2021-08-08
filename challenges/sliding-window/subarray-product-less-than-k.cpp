// https://leetcode.com/problems/subarray-product-less-than-k/

/*  
  Logic - SF
  Code  - Sliding Window
*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
      int m=0, j=0;
      long int prod=1;
      for(int i=0;i<nums.size();i++) {
        prod=prod*nums[i];
        while(j<=i && prod >= k) {prod=prod/nums[j++];}
        m+=i-j+1;
        
      }
      
      return m;
    }
};