// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int startx=0, starty=0, endx=matrix.size()-1, endy=matrix[0].size()-1;
        int i=0,j=0;
        vector<int> spiral;

        while(startx<=endx && starty<=endy) {
          

          for(int i=starty;i<=endy;i++) {
            spiral.push_back(matrix[startx][i]);
          } 
          startx++;
          for(int i=startx;i<=endx;i++) {
            spiral.push_back(matrix[i][endy]);
          }
          endy--;
          if(startx<=endx)
          for(int i=endy;i>=starty;i--) {
            spiral.push_back(matrix[endx][i]);
          } 
          endx--;
          if(starty<=endy)
          for(int i=endx;i>=startx;i--) {
            spiral.push_back(matrix[i][starty]);
          }
          starty++;
        }

      return spiral;
    }
};