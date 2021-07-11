// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts

class Solution {
public:
    int findTheLongestSubstring(string s) {
      vector<int> ct(32, INT_MAX);
      ct[0]=-1;
      set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
      int out=0, mask=0;

      for(int i=0;i<s.length();i++) {
        if (vowels.count(s[i])) {
          int it = 0;
          for (char u : vowels) {
              if (u == s[i]) break;
              it++;
          }
          mask^= (1<<it);
          if(ct[mask]==INT_MAX) {
            ct[mask] = i;
          }
        }
        out=max(out, i - ct[mask]);
      }
      
      return out;
    }
};