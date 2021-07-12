// https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/

// NOTE Remember to make sum 0

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
      unordered_set<int> s;
      int sum=0, out=0;
      s.insert(0);
      for(int i=0;i<nums.size();i++) {
        sum+=nums[i];
        if(s.count(sum-target)) {
          out++;
          s={0};
          sum=0;
        }
        s.insert(sum);
      }
      return out;
    }
};