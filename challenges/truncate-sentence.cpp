// https://leetcode.com/problems/truncate-sentence

class Solution {
public:
    string truncateSentence(string s, int k) {
      int ct =0;
      string out ="";
      for (int i=0;i<s.length();i++) {
        if(s[i]==' ') ct++;
        if(ct ==k) {break;}
        out.push_back(s[i]);
      }
      return out;
    }
};