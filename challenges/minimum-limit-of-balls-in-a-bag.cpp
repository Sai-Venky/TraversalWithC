// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/

class Solution {
public:
    bool isPossible(vector<int>& nums, int v, int maxOperations) {
      int steps=0;
      for(auto x : nums) {
        if(x <= v) continue;
        steps += x / v - (x % v == 0);
      }

      return steps > maxOperations ? false : true;

    }
  
    int minimumSize(vector<int>& nums, int maxOperations) {
      int l=1, n=nums.size();
      int h=0, m;
      for(auto num:nums) {
        if(num>h) h=num;
      }
      
      
      while(l<=h) {
        m = l + (h-l)/2;
        bool p = isPossible(nums, m , maxOperations);
        if(p) {
          h=m-1;
        } else {
          l=m+1;
        }
      }
      
      return l;
      
    }
};