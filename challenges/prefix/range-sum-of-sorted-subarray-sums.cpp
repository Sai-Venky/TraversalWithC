// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
      vector<long> roll(n+1, 0);
      multiset<long> result;

      long s=nums[0];
      for(int i=1;i<n+1;i++) {
        roll[i] += s + roll[i-1];
        s = nums[i];
      }
      
      for(int i=1;i<n+1;i++) {
        int k=0;
        while(k<i) {
          result.insert(roll[i] - roll[k++]);
        }
      }
      long sum=0;
      int i=1;
      for (auto itr: result){
        if(i>=left&&i<=right)
          sum+=itr;
        i++;
      }
      return sum % 1000000007;
      
      
    }
};