// https://leetcode.com/problems/maximum-width-ramp

/*
    Note the use of decreasing stack here.
    For each element from back, we find the maximum distance in stack and popit.
    REASON FOR POPPING (Intuition) is that next element will anyways have lesser distance only with that.
*/

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
      
      vector<int> stk;
      int out=0;
      for(int i=0;i<nums.size();i++) {
        if(stk.empty() || nums[stk.back()]>nums[i]) {
          stk.push_back(i);
        }
      }
      
      for(int i=nums.size()-1;i>=0;i--) {
        while(!stk.empty() && stk.back() > i) {
          stk.pop_back();
        }
        while(!stk.empty() && nums[stk.back()]<=nums[i]) {
          out=max(out, i-stk.back());
          stk.pop_back();
        }
      }
      
      return out;
    }
};