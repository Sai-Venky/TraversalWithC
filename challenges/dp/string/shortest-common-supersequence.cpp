// https://leetcode.com/problems/shortest-common-supersequence/

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
      int m=str1.length(), n=str2.length();
      vector<vector<int>> dp(m+1, (vector<int>(n+1, 0)));
      for(int i=1;i<m+1;i++) {
        for(int j=1;j<n+1;j++) {
          if(str1[i-1] == str2[j-1]) {
            dp[i][j] = 1 + dp[i-1][j-1];
          } else {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);            
          }
        }
      }
      int i=m, j=n;
      string res="";
      while(i>0 || j>0) {
        if(i>0 && dp[i][j] == dp[i-1][j]) {
          res=str1[--i]+res;
        } else if (j>0 && dp[i][j] == dp[i][j-1]){
          res=str2[--j]+res;
        } else {
          res=str1[--i]+res;j--;
        } 
      }
      return res;
    }
};