// https://leetcode.com/problems/jump-game-ii/

/*
    Keep track of the reach and end.
*/

class Solution {
public:
    int jump(vector<int>& nums) {
      int end=0, reach=0;
      int ct=0;
      for(int i=0;i<nums.size()-1;i++) {
        reach=max(reach, i+nums[i]);
        if(end==i) {
          ct++;
          end=reach;
        }
      }
      return ct;
    }
};