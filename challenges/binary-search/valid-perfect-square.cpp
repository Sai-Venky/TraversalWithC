// https://leetcode.com/problems/valid-perfect-square

class Solution {
public:
    bool isPerfectSquare(int num){
      
      long l=0, h =num, m;
      while(l<=h) {
        m = l +(h-l)/2;
        if(m*m > num) {
          h=m-1;
        } else {
          l=m+1;
        }
      }
      return h*h == num;
      
    }
};