// https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
      
      long l=0, h =x, m;
      while(l<=h) {
        m = l +(h-l)/2;
        if(m*m > x) {
          h=m-1;
        } else {
          l=m+1;
        }
      }
      return h;
      
    }
};