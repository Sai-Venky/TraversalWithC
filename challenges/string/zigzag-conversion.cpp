// https://leetcode.com/problems/zigzag-conversion/

class Solution {
public:
   string convert(string s, int numRows) {
    if(numRows == 1) return s;
    vector<string> st(numRows, "");
    int i=0,j=0;
    while(i<s.length()) {
      
      while(i<s.length() && j<numRows-1) {
        st[j++] += s[i++];
      }
      
      while(i<s.length() && j>0) {
        st[j--] += s[i++];
      }
      
    }
    string out;
    for(auto val: st) {
      out+= val;
    }
     return out;
  }
};