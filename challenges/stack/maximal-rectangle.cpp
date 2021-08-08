// https://leetcode.com/problems/maximal-rectangle

/*

/*  
  Logic - SF
  Code  - Note the use of stack and addition of 0 in end to triiger computation in largestRectangleArea function

  int maximalRectangle(vector<vector<char> > &matrix) {
    if(matrix.empty()){
        return 0;
    }
    int maxRec = 0;
    vector<int> height(matrix[0].size(), 0);
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            if(matrix[i][j] == '0'){
                height[j] = 0;
            }
            else{
                height[j]++;
            }
        }
        maxRec = max(maxRec, largestRectangleArea(height));
    }
    return maxRec;
  }

  int largestRectangleArea(vector<int> &height) {
        stack<int> s;
        height.push_back(0);
        int maxSize = 0;
        for(int i = 0; i < height.size(); i++){
            if(s.empty() || height[i] >= height[s.top()]){
                s.push(i);
            }
            else{
                int temp = height[s.top()];
                s.pop();
                maxSize = max(maxSize, temp * (s.empty() ? i : i - 1 - s.top()));
                i--;
            }
        }
        return maxSize;
  }
*/

/*  
  Logic - SF
  Code  - Store both rows and cols in meta data
*/


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& arr) {
      if(arr.size() == 0) return 0;
      int m=arr.size(), n=arr[0].size(), maxrec=0;
      vector<vector<int>> mat(m, vector<int>(n, 0));
      for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
          mat[i][j] = j>0 && arr[i][j] == '1'? mat[i][j-1]+1:arr[i][j] - '0';
        }
      }
      
      for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
          int res = INT_MAX;
          for(int k=i;k<m;k++) {
            res = min(res, mat[k][j]);
            maxrec=max(maxrec, res*(k-i+1));
          }
        }
      }
      return maxrec;
    }
};