// https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
      int k=0;
      for(char c:t) {
        if(s[k] == c) k++;
      }
      return k==s.size();
    }
};