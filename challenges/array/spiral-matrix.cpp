// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startx=0, starty=0, endx=matrix.size()-1, endy=matrix[0].size()-1;
        int i=0,j=0;
        vector<int> spiral;

        while(startx<=endx && starty<=endy) {
          
          for(j=starty;j<=endy;j++) {
            cout<<" "<<matrix[i][j];
            spiral.push_back(matrix[i][j]);
          } 
          j--;
          for(i=startx+1;i<=endx;i++) {
            cout<<" "<<matrix[i][j];
            spiral.push_back(matrix[i][j]);
          }
          i--;
          if(startx<endx)
          for(j=endy-1;j>=starty;j--) {
            cout<<" "<<matrix[i][j];
            spiral.push_back(matrix[i][j]);
          } 
          j++;
          if(starty<endy)
          for(i=endx-1;i>=startx+1;i--) {
            cout<<" "<<matrix[i][j];
            spiral.push_back(matrix[i][j]);
          }
          i++;
          endy--;
          startx++;
          starty++;
          endx--;
        }

      return spiral;
    }
};