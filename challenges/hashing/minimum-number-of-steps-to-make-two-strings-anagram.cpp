// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram

class Solution {
public:
    int minSteps(string s, string t) {
      unordered_map<char, int> m;
      for(char c:s) m[c]++;
      for(char c:t) if(m.find(c)!=m.end()) m[c]--;
      int out=0;
      for(auto v:m) {
        if(v.second>0) out+=v.second;
      }
      return out;
    }
};