// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

/*
    Just keep the cuts in dp array.
    Calculate each cut and distnce and build up for entire array/
    Note:- adding 0, n in array and only considering cuts.
*/

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
      cuts.push_back(0);
      cuts.push_back(n);
      sort(cuts.begin(), cuts.end());
      int m=cuts.size();
      vector<vector<int>> dp(m, vector<int>(m, INT_MAX));
      
      for(int i=0;i<m;i++) dp[i][i]=0;
      for(int i=1;i<m;i++) dp[i-1][i]=0;
      
      for(int l=2;l<m;l++) {
        
        for(int s=0;s<m-l;s++) {
          int e=s+l;
          for(int k=s+1;k<e;k++) {
            dp[s][e] = min(dp[s][e], dp[s][k] + dp[k][e] + (cuts[e]-cuts[s]));
          }
          
        }
      }
      return dp[0][m-1];
      
    }
};