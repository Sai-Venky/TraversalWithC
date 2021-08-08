// https://leetcode.com/problems/shortest-palindrome

// https://leetcode.com/problems/shortest-palindrome/discuss/60216/A-KMP-based-Java-solution-with-explanation
// https://leetcode.com/problems/shortest-palindrome/discuss/60204/Using-KMP's-LPS-(longest-prefix-suffix)-computation-to-solve-in-linear-O(N)-time
class Solution {
public:
    int lps_compute(string s) {
      string rev=s;
      reverse(rev.begin(), rev.end());
      s = s + '#' + rev ;
      
      int n=s.length();
      vector<int> lps(n, 0);
      
      for(int i=1;i<n;i++) {
        int j=lps[i-1];
        while(j>0 && s[i]!=s[j]) {
          j=lps[j-1];
        }
        lps[i] = j + (s[i] == s[j] ? 1 : 0);
      }
      return lps[n-1];
    }
      
    string shortestPalindrome(string s) {
      if (s.size() <= 1) return string(s);
      int pos = lps_compute(s);      
      string the_rest = s.substr(pos);
      reverse(the_rest.begin(), the_rest.end());
      return the_rest + s;
    }
};
