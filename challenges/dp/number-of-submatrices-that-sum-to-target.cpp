// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target

class Solution {
  public:
  int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
    int m=A.size(), n=A[0].size(), ct=0;
    for(int i=0;i<m;i++) {
      for(int j=0;j<n;j++) {
        A[i][j] += j==0?0:A[i][j-1];
      }
    }
    unordered_map<int, int> mp;
    for(int k=0;k<n;k++) {
      
      for(int j=k;j<n;j++) {
        int sum=0;
        mp = {{0,1}};
        for(int i=0;i<m;i++) {
          
          sum += A[i][j] - (k-1>=0?A[i][k-1]:0);
          ct+= (mp.find(sum-target) != mp.end())? mp[sum-target]:0;
          mp[sum]++;
        }
        
      }
      
    }
    
    return ct;
  }
};