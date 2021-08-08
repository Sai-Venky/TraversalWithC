// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses

/*  
    Logic - Note the marking of backward oass with stack itself and marking of strings with * and later removal 
    Code - Stack
*/

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