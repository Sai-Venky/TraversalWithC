// https://leetcode.com/problems/solve-the-equation

class Solution {
public:
    string solveEquation(string e) {
      
      int x=0, v=0, xsign=1, vsign=-1;
      e.push_back('=');
      string s="";
      
      for(int i=0;i<e.length();i++) {
        
        if(!s.empty() && (e[i]=='+' || e[i]=='-' || e[i]=='=') ){
          if(s.back()=='x') {
            s.pop_back();
            if(s=="" || s=="+" || s=="-") s.push_back('1');
            x+=(xsign*stoi(s));
          } else v+=(vsign*stoi(s)); 
          s="";
        }
        
        if(e[i]!='=') s.push_back(e[i]);
        
        if(e[i]=='='){
          xsign=-1;
          vsign=1;
        }
      }
      
      if(x==0 && v==0) {
        return "Infinite solutions";
      } else if(x==0 && v!=0) {
        return "No solution";
      } else {
        return "x=" + to_string(v/x);
      }
    }
};