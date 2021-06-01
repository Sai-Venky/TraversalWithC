// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    
    int climbStairs(int n) {
     if(n==1) {
        return 1;
      }
      int one=1, two=2;
      for(int i=2;i<n;i++) {
        int three=one+two;
        one=two;
        two=three;
      }
      return two;
    }
};