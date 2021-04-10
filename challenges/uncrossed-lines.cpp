// https://leetcode.com/problems/uncrossed-lines

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
      vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
      int i,j;
      for(i=1; i<dp.size(); i++) {
        for(j=1; j<dp[i].size(); j++) {
          int eq=A[i-1]==B[j-1]?1:0;

          dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+eq});
        }
      }
      
      return dp[i-1][j-1];
    }
};
