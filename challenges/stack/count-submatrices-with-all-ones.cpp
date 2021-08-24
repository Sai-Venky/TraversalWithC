// https://leetcode.com/problems/count-submatrices-with-all-ones/

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
      int m=mat.size(), n=mat[0].size(), ct=0;
      for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
          if(j!=0) mat[i][j] = mat[i][j] == 1? mat[i][j-1] + 1:mat[i][j];
        }
      }
      
      for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
          int res = INT_MAX;
          for(int k=i;k<m;k++) {
            
            res = min(res, mat[k][j]);
            ct+=res;
          }
        }
      }
      return ct;
    }
};

/*
  
  [1,1,1]
  [1,1,0]
  [1,1,0]
  [1,1,0]

  1, 2, 3
  1, 2, 0
  1, 2, 0
  1, 2, 0
  
*/