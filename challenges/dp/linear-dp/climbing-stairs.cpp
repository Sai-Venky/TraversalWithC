// https://leetcode.com/problems/climbing-stairs


/*
The key intuition to solve the problem is that given a number of stairs n, if we know the number ways to get to the points [n-1] and [n-2] respectively, denoted as n1 and n2 , then the total ways to get to the point [n] is n1 + n2. 
Because from the [n-1] point, we can take one single step to reach [n]. And from the [n-2] point, we could take two steps to get there.
*/
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