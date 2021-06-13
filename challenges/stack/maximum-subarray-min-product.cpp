// https://leetcode.com/problems/maximum-subarray-min-product

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
      vector<long> prefix = {0}; 
      for (auto x : nums) 
          prefix.push_back(prefix.back() + x); 

      long ans = 0; 
      stack<pair<int, int>> stk; 
      nums.push_back(0); 

      for (int i = 0; i < nums.size(); ++i) {
          int ii = i; 
          while (stk.size() && stk.top().second >= nums[i]) {
              ii = stk.top().first; 
              int val = stk.top().second; 
              ans = max(ans, val * (prefix[i] - prefix[ii])); 
              stk.pop(); 
          }
          stk.push(make_pair(ii, nums[i])); 
      }
      return ans % 1'000'000'007; 
    }
  
};