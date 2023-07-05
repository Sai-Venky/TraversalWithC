// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
      int n=s.length();
      vector<vector<bool>> dp(n, vector<bool>(n, 0));
      int start=0, end=0;
      for(int i=0;i<n;i++) dp[i][i]=true;
      for(int i=1;i<n ;i++) {
        if((s[i-1] == s[i])) {
          dp[i-1][i]=true;
          start=i-1; end=i;
        }
      } 
      
      for(int l=2;l<n;l++) {
        for(int i=0;i<n-l;i++) {
          dp[i][i+l] = (s[i+l] == s[i]) && dp[i+1][i+l-1];
          if(dp[i][i+l]) {
            start=i;end=i+l;
          }
        }
      }
      return s.substr(start, end-start+1);
    }
};

// Longest Palindrome
class Solution {
public:
    string longestPalindrome(string s) {
        string count = ""; int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        for (int d = 0; d < n; d++) {
            for (int i = 0; i+d < n; i++) {
                int j = i + d;
                if (s[i] == s[j]) {
                    dp[i][j] = (i+1 >= j-1) ? true : dp[i+1][j-1];
                    if(dp[i][j]) count = s.substr(i, j-i+1);
                }                
            }
        }
        return count;
    }
};

// Palindromic Substrings
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0, n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        for (int d = 0; d < n; d++) {
            for (int i = 0; i+d < n; i++) {
                int j = i + d;
                if (s[i] == s[j]) {
                    dp[i][j] = (i+1 >= j-1) ? true : dp[i+1][j-1];
					          if (dp[i][j]) count++;
                }                
            }
        }
        return count;
    }
};

