// https://leetcode.com/problems/01-matrix

/*  
  Logic - BFS
  Code  - using dirs and marking other value as -1 to ensure its not used again (Visited).
*/

class Solution {
public:
  
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
      int m=matrix.size(), n=matrix[0].size();
      vector<vector<int>> dir = {{-1,0}, {1,0}, {0,1}, {0, -1}};   
      queue<pair<int,int>> q;
      
      for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
          if(matrix[i][j] == 0) {
            q.push({i, j});
          } else {
            matrix[i][j] = -1;
          }
        }
      }
      while(!q.empty()) {
        int l = q.size();
        for(int i=0; i<l; i++) {
          pair <int, int> pairval = q.front();
          for(auto val: dir) {
            int x = pairval.first + val[0]; 
            int y = pairval.second + val[1];
            if(x>=0 && y>=0 && x<m && y<n && matrix[x][y] == -1) {
              q.push({x,y});
              matrix[x][y] = matrix[pairval.first][pairval.second]+1;
            }
          }
          q.pop();
        }
      }
      return matrix;
    }
};