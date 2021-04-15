// https://leetcode.com/problems/fibonacci-number

class Solution {
public:
    int fib(int n) {
      if(n==0) {
        return 0;
      }
      int one=0, two=1;
      for(int i=2;i<=n;i++) {
        int three=one+two;
        one=two;
        two=three;
      }
      return two;
    }
};