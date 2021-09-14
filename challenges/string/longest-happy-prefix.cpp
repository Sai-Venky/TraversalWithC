// https://leetcode.com/problems/longest-happy-prefix/

// https://leetcode.com/problems/longest-happy-prefix/discuss/547204/C%2B%2B-KMP-preprocessing
// Refer shortest-palindrome
// note the use for substring match checking
 
class Solution {
public:
    string longestPrefix(string s) {
      int n=s.length();
      vector<int> lps(n, 0);
      
      for(int i=1, j=0;i<n;i++) {
        while(j>0 && s[i]!=s[j]) j=lps[j-1];
        if (s[i]==s[j]) lps[i] = ++j;
      }
      
      return s.substr(0, lps.back());
    }
};