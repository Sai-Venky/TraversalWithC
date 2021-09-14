// https://leetcode.com/problems/shortest-palindrome

// https://leetcode.com/problems/shortest-palindrome/discuss/60216/A-KMP-based-Java-solution-with-explanation
// https://leetcode.com/problems/shortest-palindrome/discuss/60204/Using-KMP's-LPS-(longest-prefix-suffix)-computation-to-solve-in-linear-O(N)-time

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;
        int n=l.length();
        vector<int> lps(n, 0);
        
        for(int i=1, j=0;i<n;i++) {
          while(j>0 && l[i]!=l[j]) j=lps[j-1];
          if (l[i]==l[j]) lps[i] = ++j;
        }
        
        return rev_s.substr(0, s.size() - lps[n-1]) + s;
    }
};