// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      int j=0;
      int m=0;
      for(int i=0;i<nums.size();i++) {
        if(nums[i]==0) { 
          k--;
        }
        
        while(k<0) {
          if(nums[j++]==0) {k++;}
        }
        m = max(i-j+1, m);

      }
      
      return m;
    }
};