// https://leetcode.com/problems/count-sub-islands

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &B, vector<vector<int>>& A, bool *valid) {
      if(i<0 || j<0 || i>=B.size() || j>=B[0].size() || B[i][j]!=1) return;
      
      B[i][j]=-1;
      if(A[i][j]!=1) *valid=false;
      dfs(i+1, j, B, A, valid);
      dfs(i-1, j, B, A, valid);
      dfs(i, j+1, B, A, valid);
      dfs(i, j-1, B, A, valid);
    }
    
    int countSubIslands(vector<vector<int>>& A, vector<vector<int>>& B) {
      int m=A.size(), n=A[0].size();
      int out=0;
      for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
          if(B[i][j]==1) {
            bool valid=true;
            dfs(i, j, B, A, &valid);
            if(valid) out++;
          }
        }
      }
      
      return out;
    }
};