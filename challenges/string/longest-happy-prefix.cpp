// https://leetcode.com/problems/longest-happy-prefix/

// https://leetcode.com/problems/longest-happy-prefix/discuss/547204/C%2B%2B-KMP-preprocessing
// Refer shortest-palindrome
 
class Solution {
public:
    string longestPrefix(string s) {
      int n=s.length();
      vector<int> lps(n, 0);
      
      for(int i=1;i<n;i++) {
        int j=lps[i-1];
        while(j>0 && s[i]!=s[j]) {
          j=lps[j-1];
        }
        lps[i] = j + (s[i] == s[j] ? 1 : 0);
      }
      return s.substr(0, lps.back());
    }
};