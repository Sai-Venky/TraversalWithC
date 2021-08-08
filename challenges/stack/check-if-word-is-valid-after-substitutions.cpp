// https://leetcode.com/problems/check-if-word-is-valid-after-substitutions

/*
  Logic - Stack
  Code - Note the use of counters, and validating them
*/

class Solution {
public:
    bool isValid(string s) {
      
      stack<int> t;
      
      for(int i=0;i<s.length();i++) {
        
        if(s[i] == 'a') {
          t.push(0);
        } else if(s[i] == 'b') {
          if(t.empty()) return false;
          t.top()++;
        } else {
          if(t.empty() || t.top()!=1) return false;
          t.pop();
        }
      }
      
      return t.empty()?true:false;
    }
};