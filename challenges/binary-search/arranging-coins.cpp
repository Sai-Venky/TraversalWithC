// https://leetcode.com/problems/arranging-coins/

/*
  Logic - SF
  Code - BS
 */

class Solution {
public:
    int arrangeCoins(int n) {
      
      long l=0, h =n, m;
      while(l<=h) {
        m = l +(h-l)/2;
        if(m*(m+1) > 2 * long(n)) {
          h=m-1;
        } else {
          l=m+1;
        }
      }
      return h;
      
    }
};