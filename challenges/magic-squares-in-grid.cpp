// https://leetcode.com/problems/magic-squares-in-grid

class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int i, int j) {
      int output = (grid[i][j] + grid[i][j+1] + grid[i][j+2]); 
      bool s= (output == grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2]) &&
      (output == grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2]) && 
      (output == grid[i][j] + grid[i+1][j] + grid[i+2][j]) && 
      (output == grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1]) && 
      (output == grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2]) && 
      (output == grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2]) && 
      (output == grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j]);
    
      set<int> val({1,2,3,4,5,6,7,8,9});
      for(int r = 0 ; r < 3 ; r++){
          for(int c = 0; c < 3 ; c++){
              val.erase(grid[i + r][j + c]);
          }
      }
      return s && val.empty();
    }
  
    int numMagicSquaresInside(vector<vector<int>>& grid) {
      int n=grid.size();
      int m = grid[0].size();
      int ct=0;
      for(int i=0;i<n-2; i++) {
        for(int j=0; j<m-2; j++) {
          ct = isMagicSquare(grid, i, j)?ct+1:ct;
        }
      }
      return ct;
    }
};