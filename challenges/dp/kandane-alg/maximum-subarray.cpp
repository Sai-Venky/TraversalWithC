// https://leetcode.com/problems/maximum-subarray
// https://leetcode.com/problems/maximum-subarray/solutions/20193/dp-solution-some-thoughts/?orderBy=most_votes

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      
      int max_sum=INT_MIN, i=0;
      int sum=0;
      for(int num:nums) {
        sum+=num;
        if(sum>max_sum) max_sum=sum;
        if(sum<0) sum=0;
      }
      return max_sum;
    }
};