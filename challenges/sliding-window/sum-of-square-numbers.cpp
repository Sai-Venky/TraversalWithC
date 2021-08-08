// https://leetcode.com/problems/sum-of-square-numbers/

class Solution {
public:
    bool judgeSquareSum(int c) {
      long l=0, h=sqrt(c);
      
      while(l<=h) {
        long v=h*h + l*l;
        if(v == c) return true;
        else if (v>c) h--;
        else l++;
      }
      return false;
    }
};