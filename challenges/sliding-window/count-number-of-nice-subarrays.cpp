// https://leetcode.com/problems/count-number-of-nice-subarrays/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
      int ct=0, n=nums.size();
      deque<int> q = {-1};
      
      for(int i=0; i<nums.size(); i++) {
        if(nums[i] % 2) q.push_back(i);
        if(q.size() > k+1) q.pop_front();
        if(q.size() == k+1) ct+=q[1] - q[0];
      }
      return ct;
    }
};