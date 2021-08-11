// https://leetcode.com/problems/unique-substrings-in-wraparound-string

/*
    Counting the characters in a seperate 26 len array and keeping track of the uniqueness
*/
class Solution {
public:
    int findSubstringInWraproundString(string p) {
      int out=0, cur=1;
      
      vector<int> dp(26, 0);
      dp[p[0]-'a']=cur;
      
      for(int i=1;i<p.length();i++) {
        
        if(p[i]-p[i-1]==1 || (p[i-1]=='z' && p[i]=='a')) {
          cur++;
        } else {
          cur=1;
        }
        dp[p[i]-'a'] = max(dp[p[i]-'a'], cur);
      }
      
      for(int v:dp) {
        out+=v;
      }
      return out;
    }
};