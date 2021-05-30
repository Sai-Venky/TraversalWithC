// https://leetcode.com/problems/push-dominoes/

/*
    Traverse from left to right, then from right to left. Take minimum of two.
*/
class Solution {
public:
    string pushDominoes(string dominoes) {
      int n=dominoes.length();
      vector<int> dp(n, -1);
      string out = dominoes;
      
      for(int i=0, r=-1;i<n;i++) {
        if(dominoes[i] == 'R') r=0;
        else if(dominoes[i] == 'L') r=-1;
        dp[i] = r;
        r = r!=-1?r+1:r;
      }
      
      for(int i=n-1, l=-1;i>=0;i--) {
        if(dominoes[i] == 'L') l=0;
        else if(dominoes[i] == 'R') l=-1;
        
        if(l<0 && dp[i]<0) out[i] = '.';
        else if(l<dp[i] && l!=-1 || dp[i] == -1) out[i] = 'L';
        else if(l>dp[i] && dp[i]!=-1 || l == -1) out[i] = 'R';
        
        l = l!=-1?l+1:l;
      }
      
      return out;
    }
};
