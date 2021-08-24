// https://leetcode.com/problems/jump-game

// note the logic

class Solution {
public:
    bool canJump(vector<int>& nums) {
      int m=nums[0];
      int i=0;
      while(i<=m) {
        if(i>=nums.size()-1) return true;
        m=max(m, i+nums[i]);
        i++;
        
      }
      return false;
    }
};