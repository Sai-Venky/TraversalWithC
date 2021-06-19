// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent


class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
      int i=0;

      string s, s2;
      for(auto val: word1) {
        for(auto c: val) {
          s.push_back(c);   
        }
      }
      for(auto val: word2) {
        for(auto c: val) {
          if(s.length() == i || s[i++]!=c) return false;   
        }
      }
      return s.length() == i ? true: false;
    }
};