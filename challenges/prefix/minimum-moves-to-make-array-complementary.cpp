// https://leetcode.com/problems/minimum-moves-to-make-array-complementary/

// https://leetcode.com/problems/minimum-moves-to-make-array-complementary/discuss/953078/Prefix-sum-O(n-%2B-limit)-with-detailed-examples-and-pseudocode

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
      
      int n=nums.size();
      vector<int> roll(limit*2+2,0);
      
      for(int i=0;i<n/2;i++) {
        int l=nums[i], r=nums[n-i-1];
        int mi = min(l, r);
        int ma = max(l, r);
        
        --roll[mi+1];
        --roll[l + r];
        ++roll[l + r + 1];
        ++roll[ma+limit+1];
      }
      
      int ans = n, curr = n;
      for (int i = 2; i <= limit*2; ++i) {
        curr += roll[i];
        ans = min(ans, curr);
      }
      return ans;
      
    }
};
