// https://leetcode.com/problems/arithmetic-slices

/* 
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<int> dp(A.size());
        int res = 0;
        for (int i = 2; i < A.size(); i++) {
            if (A[i] - A[i-1] == A[i-1] - A[i-2]) {
                dp[i] = dp[i-1] + 1;
                res += dp[i];
            }
        }
        return res;
    }
};
*/

/*  
  Logic - SF
  Code  - Using Sliding Window
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
      
      int n=nums.size();
      int ct=0;
      
      for(int r=1,l=0;r<n-1;r++) {
        if(nums[r+1]-nums[r] == nums[l+1]-nums[l] && r-l+1>=2) ct+=(r-l);
        else l=r;
      }
      return ct;
    }
};