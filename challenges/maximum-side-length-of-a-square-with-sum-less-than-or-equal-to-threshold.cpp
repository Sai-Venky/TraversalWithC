// https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold

class Solution {
public:
    int side;
    void checkSum(vector<vector<int>>& mat, int tlx, int tly, int blx, int bly, int thr, vector<vector<int>>& dp) {
      int sum=0;
      if(blx!=tlx && bly!=tly) {
        sum+=dp[tlx][tly];
      }
      if(sum > thr) {dp[tlx][tly] = sum;return;}
      
      for(int i=tlx; i<blx; i++) {
        sum+=mat[i][bly];
      }
      for(int i=tly; i<bly; i++) {
        sum+=mat[blx][i];
      }
      sum+=mat[blx][bly];

      if(sum<=thr && side<(blx-tlx+1)) {
        side=(blx-tlx+1);
      }
      dp[tlx][tly] = sum;
    }
  
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
      side=0;
      int m=mat.size(), n=mat[0].size(), tlx, tly;
      vector<vector<int>> dp(m, vector<int> (n, 0));
      int sq_size=min(m, n);
      for(int k=0;k<sq_size;k++) {
        for(int i=k;i<m;i++) {
          for(int j=k;j<n;j++) {
            tlx=i-k; tly=j-k;
            checkSum(mat, i-k, j-k, i, j, threshold, dp);
          }
        }
      }
      return side;
    }
};