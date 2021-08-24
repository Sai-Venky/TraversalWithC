// https://leetcode.com/problems/simplify-path/

/*
    SF
*/

class Solution {
public:
    string simplifyPath(string path) {
      string out="", name="";
      vector<string> stk;
      int i=0;
      while(i<path.length()) {
        
        while(path[i]=='/') i++;
        while(i<path.length() && path[i]!='/') name.push_back(path[i++]);
        
        if(name=="..") { if(!stk.empty()) stk.pop_back();}
        else if(name!="" && name!=".") {stk.push_back(name); }
        
        i++;
        name="";
      }
      
      for(int i=0;i<stk.size();i++) {
        out+= '/' + stk[i];
      }
      
      return out.size()==0?"/":out;
    }
};