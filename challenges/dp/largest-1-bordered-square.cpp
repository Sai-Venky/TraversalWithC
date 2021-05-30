// https://leetcode.com/problems/largest-1-bordered-square


/*
    Find vertical and horizontal 1s for each position. Then check if same vertical and horizontal exists in opposite diagnol part alsp.
    x------------y
    |            |
    |            |
    |            |
    z----------- w

    like w-z and w-y there , then check if x-z and x-y there
*/

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
      int max = 0; int m = grid.size() , n = grid[0].size();
      vector<vector<int>> hor(m,vector<int> (n,0)) , ver(m,vector<int> (n,0));
      
      for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
          if(grid[i][j]) {
            hor[i][j] = (j==0)?1:hor[i][j-1]+1;
            ver[i][j] = (i==0)?1:ver[i-1][j]+1;
          }
        }
      }
      
      for(int i=m-1;i>=0;i--) {
       for(int j=n-1;j>=0;j--) {
          int small = min(hor[i][j], ver[i][j]);
          while(small>max) {
            if(hor[i-small+1][j] >= small && ver[i][j-small+1]>=small) {
              max=small;
              break;
            }
            small--;
          }
        } 
      }
      return max*max;
    }
};
