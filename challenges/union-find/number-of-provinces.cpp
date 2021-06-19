// https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
 	  vector<int>rankmat;
    int parent(int i) {
      if(rankmat[i] !=i) {
        rankmat[i] = parent(rankmat[i]);
      }
      return rankmat[i];
    }
  
    int findCircleNum(vector<vector<int>>& isConnected) {
      int n = isConnected.size(), ct= n;
      rankmat.resize(n, -1);
      
      for(int i=0;i<n;i++){
        rankmat[i] = i;
      }
      
      for(int i=0;i<n;i++) {
        for(int j=i; j<n; j++) {
          int x = parent(i);
          int y = parent(j);
          if(isConnected[i][j]) {
            if(x!=y) {
              if(x > y) {
                rankmat[x] = y;
              } else {
                rankmat[y] = x;
              }
              ct--;
            }
          }
        }
      }
      
      return ct;
    }
};