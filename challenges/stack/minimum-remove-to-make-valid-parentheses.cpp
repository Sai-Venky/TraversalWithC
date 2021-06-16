// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses

class Solution {
public:
    string minRemoveToMakeValid(string str) {
      string out;
      stack<int> s;
      int n=str.length();
      
      for(int i=0;i<n;i++) {
        
        if(str[i]=='(') {
          s.push(i);
        } else if(str[i] ==')') {
          if(s.empty()) str[i] = '*';
          else s.pop();            
        }
        
      }
      while(!s.empty()) {
        str[s.top()] = '*';
        s.pop();
      }
      
      for(int i=0;i<n;i++) {
        if(str[i] != '*') out.push_back(str[i]);
      }
      
      return out;
    }
};