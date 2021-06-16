// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses

class Solution {
public:
    string reverseParentheses(string str) {
      int n=str.length();
      
      stack<int> s;
      string out;
      for(int i=0;i<n;i++) {
        
        if(str[i]=='(') {
          s.push(i);
        } else if(str[i] ==')') {
          int l=s.top();s.pop();
          int h=i;
          while(l<h) swap(str[l++], str[h--]);
        }
        
      }
      for(char c:str) {
        if( c!=')' && c!='(' ) {
          out+=c;
        }
      }
      
      return out;
    }
};