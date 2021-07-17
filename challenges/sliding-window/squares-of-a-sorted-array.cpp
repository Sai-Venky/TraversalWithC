// https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      int n=nums.size();
      vector<int> out(n, 0);
      int l=0, r=n-1;
      int k=n-1;
      while(l<=r) {
        
        if(abs(nums[l])>abs(nums[r])) {
          out[k--] = (nums[l]*nums[l]);
          l++;
        } else {
          out[k--] = (nums[r]*nums[r]);
          r--;
        }
        
      }
      
      return out;
    }
};