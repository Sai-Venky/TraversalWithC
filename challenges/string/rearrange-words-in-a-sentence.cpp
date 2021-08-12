// https://leetcode.com/problems/rearrange-words-in-a-sentence

// SF. Note the use of string itself instead of storing as vector<string>

class Solution {
public:
    string arrangeWords(string text) {
      
      map<int, string> m;
      text.push_back(' ');
      text[0] = tolower(text[0]);
      string cal="";
      for(int i=0;i<text.length();i++) {
        if(text[i]!=' ') cal.push_back(text[i]);
        else {
          if(m[cal.size()].empty()) m[cal.size()] = cal;
          else m[cal.size()] = m[cal.size()] + " " + cal;
          cal="";
        }
      }
      string out="";
      for(auto v:m) {
        out=out+v.second+" ";
      }
      
      out.pop_back();
      out[0]= toupper(out[0]);
      return out;
    }
};