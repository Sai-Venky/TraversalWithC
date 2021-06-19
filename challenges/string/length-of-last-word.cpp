// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
      int l=0;
      for(int i=s.length()-1; i>=0;i--) {
        if(s[i]!=' ')  {
          l++;
        } else {
          if(l>0) break;
        } 
      }
      return l;
    }
};