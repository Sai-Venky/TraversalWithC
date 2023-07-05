// https://leetcode.com/problems/maximal-rectangle

/*

/*  
  Logic - SF
  Code  - Note the use of stack and addition of 0 in end to triiger computation in largestRectangleArea function

Same implementation as largest rectange in histogram.
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<int> heights(n, 0);
        int maxi = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j]=0;
                }
            }
            
            vector<int> tracker;
            int n=heights.size();
            heights.push_back(0);
            tracker.push_back(-1);
            for(int j=0;j<n+1;j++) {
                while(tracker.back()!=-1 && heights[tracker.back()] > heights[j]) {
                        int temp = tracker.back();
                        tracker.pop_back();
                        maxi = max(maxi, heights[temp] * (j-tracker.back()-1));
                }

                tracker.push_back(j);
            }
            heights.pop_back();

        }

        return maxi;
    }
};
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