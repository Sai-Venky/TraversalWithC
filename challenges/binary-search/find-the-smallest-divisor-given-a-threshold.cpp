// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold

class Solution {
public:
  
    int checkDivisor(vector<int>& nums, int m) {
      int sum=0;
      for(int num:nums) {
        sum+=ceil(float(num)/m);
      }
      return sum;
    }
  
    int smallestDivisor(vector<int>& nums, int threshold) {
      int l=1, n=nums.size();
      int h=0, m;
      for(auto num:nums) {
        if(num>h) h=num;
      }
      int t=threshold;      
      while(l<=h) {
        m = l + ((h-l)/2);
        int sum = checkDivisor(nums, m);
        if(sum > threshold) {
          l = m+1;
        } else {
          h = m-1; 
        }

      }
      return l;
      
      
    }
};