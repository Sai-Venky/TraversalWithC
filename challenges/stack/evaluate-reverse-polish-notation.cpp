// https://leetcode.com/problems/evaluate-reverse-polish-notation

/*
  Logic - SF
  Code- Stack
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      
      stack<int> s;
      
      for(string token:tokens) {
        
        if(token == "+") {
          int a = s.top(); s.pop();
          int b = s.top(); s.pop();
          s.push(b+a);
        } else if(token == "-") {
          int a = s.top(); s.pop();
          int b = s.top(); s.pop();
          s.push(b-a);
        } else if(token == "*") {
          int a = s.top(); s.pop();
          int b = s.top(); s.pop();
          s.push(b*a);
        } else if(token == "/") {
          int a = s.top(); s.pop();
          int b = s.top(); s.pop();
          s.push(b/a);
        } else {
          s.push(stoi(token));
        }
      }
      
      return s.top();
    }
};