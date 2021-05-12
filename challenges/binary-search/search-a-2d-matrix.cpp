// https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      
      int r = matrix.size(), c = matrix[0].size();
      int l=0, h=(r*c)-1;
      while(l<=h) {
        int m=l+(h-l)/2;
        int s_r = m/c, s_c=m-(s_r*c) ;
        if(matrix[s_r][s_c] == target) {
          return true;
        } else if (matrix[s_r][s_c] > target) {
          h=m-1;
        } else {
          l=m+1;          
        }
      }
      return false;
      
    }
};