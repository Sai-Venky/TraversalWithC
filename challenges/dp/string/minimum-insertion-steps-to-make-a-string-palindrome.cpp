// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

class Solution {
public:
    int minInsertions(string s) {
      int n=s.size();
      vector<vector<int>> dp(n, vector<int>(n, 0));
      for(int i=0;i<n;i++) dp[i][i]=1;

      for(int l=1;l<n;l++) {
        for(int i=0;i<n-l;i++) {
          int e=i+l;
          if(s[i] == s[e]) {
            dp[i][e] = 2 + dp[i+1][e-1];
          } else {
            dp[i][e] = max(dp[i+1][e], dp[i][e-1]);
          }
        }
      }
      
      return n-dp[0][n-1];
      
    }
};