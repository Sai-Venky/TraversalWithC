// https://leetcode.com/problems/find-longest-awesome-substring/

class Solution {
public:
    int longestAwesome(string s) {
      int out=0, mask=0;
      vector<int> ct(1024, s.size());
      ct[0]=-1;
      for(int i=0;i<s.length();i++) {
        mask^=1<<(s[i]-'0');
        out=max(out, i-ct[mask]);
        for(int k=0;k<10;k++) {
          out=max(out, i-ct[mask ^ (1<<k)]);
        }
        ct[mask] = min(ct[mask], i);
        
      }
      
      return out;
    }
};