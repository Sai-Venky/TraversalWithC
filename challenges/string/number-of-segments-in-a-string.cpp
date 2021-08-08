// https://leetcode.com/problems/number-of-segments-in-a-string

// SF

class Solution {
public:
    int countSegments(string s) {
      int ct=0;
      
      for(int i=0;i<s.length();i++) {
        
        if(s[i]!=' ' && (i==0 || s[i-1]== ' ')) ct++;
      }
      
      return ct;
    }
};