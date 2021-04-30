// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
      if(x<0) return false;
      long long int no=0, t=x;
      while(t) {
        int r = t %10;
        no=(no*10)+r; 
        t = t/10;
      }
      
      return x==no;
    }
};

