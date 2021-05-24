// https://leetcode.com/problems/maximum-length-of-pair-chain

class Solution {
public:
    int findLongestChain(vector<vector<int>>& es)  {
      sort(es.begin(), es.end());
      int n=es.size();
      vector<int> dp(n, 1);
      int ct=0;
      
      for(int i=0;i<n;i++) {
        
        int l=0;
        while(l<i) {
          
          if(es[i][0]>es[l][1]) {
            dp[i] = max(dp[i], dp[l]+1);
          }
          l++;
        }
        ct=max(ct, dp[i]);
      }
      
      return ct;
    }
};