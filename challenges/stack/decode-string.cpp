// https://leetcode.com/problems/decode-string

class Solution {
public:
    string decodeString(string s) {
      
      stack<pair<int, int>> t;
      string out;
      for(int i=0;i<s.length();i++) {
        
        if(isdigit(s[i])){
          string d;
          while(isdigit(s[i])) d+=s[i++];
          t.push({stoi(d), out.size()});
        } else if(s[i] == ']') {
          pair<int, int> p = t.top(); t.pop();
          string sub = out.substr(p.second, out.size()-p.second);
          while(--p.first) {
            out.append(sub);
          }
        } else {
          out+=s[i];
        }
        
      }
      return out;
      
    }
};