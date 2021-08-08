// https://leetcode.com/problems/subarray-sum-equals-k

/*
  Code - Prefix
  Logic - Prefix sum  
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      map<int, int> prefix;
      int ct=0, s=0;
      prefix[0]=1;
      for(int i=0;i<nums.size();i++) {
        s += nums[i];
        ct+=prefix[s - k];
        prefix[s]+=1;
      }
      
      return ct;
    }
};