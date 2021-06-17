// https://leetcode.com/problems/html-entity-parser

class Solution {
public:
    string entityParser(string text) {
      string out;
      unordered_map <string,string> mp = {{"&quot;","\""},
                                        {"&apos;","'"},
                                        {"&amp;","&"},
                                        {"&gt;",">"},
                                        {"&lt;","<"},
                                        {"&frasl;","/"}
                                       };
      
      for(int i=0;i<text.length();i++) {
        
        if(text[i] == '&') {
          int size = 0;
          int j = i;
          string tmp = "";
          bool found = false;
          while(j < text.length() && size <= 6){
              tmp += text[j];
              if(mp.find(tmp) != mp.end()){
                  out += mp[tmp]; 
                  i = j;
                  found = true;
                  break;
              }
              size++;
              j++;
          }
            if(!found) out += '&';
          } else {
          out+=text[i];
        }
      }
      return out;
    }
};