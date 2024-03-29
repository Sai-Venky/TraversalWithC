// https://leetcode.com/problems/sort-the-matrix-diagonally

// Note the use i-j in diagnol and priority queue

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    
      int m=mat.size(), n=mat[0].size();
      unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
      
      for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
          mp[i-j].push(mat[i][j]);
        }
      }
      
      for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
          mat[i][j] = mp[i-j].top();
          mp[i-j].pop();
        }
      }
      return mat;
    }
};