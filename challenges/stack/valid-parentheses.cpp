// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack <char> sta;
        int i=0;
        while(i<s.length()) {
          if(s[i] =='(' || s[i] =='{' || s[i] =='[') {
            sta.push(s[i]);
          } else {
            if(sta.empty()) return false;
            char ele=sta.top();
            if((ele=='(' && s[i]!=')') || (ele=='[' && s[i]!=']') || (ele=='{' && s[i]!='}')) {
              return false;
            }
            sta.pop();
          }
          i++;
        }
      if(sta.empty()) return true;
      return false;
    }
};