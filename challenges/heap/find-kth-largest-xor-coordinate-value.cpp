// https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/

/*
    Code - Heap
    Logic - Note the use of min heap here and popping everytime
*/
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
      int m=matrix.size(), n=matrix[0].size();
      priority_queue<int, vector<int>, greater<int>> q;
      
      for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
          if(i-1>=0) matrix[i][j]^=matrix[i-1][j]; 
          if(j-1>=0) matrix[i][j]^=matrix[i][j-1]; 
          if(i-1>=0 && j-1>=0) matrix[i][j]^=matrix[i-1][j-1]; 
          q.push(matrix[i][j]);
          if(q.size()>k) q.pop();
        }
      }
      return q.top();
    }
};