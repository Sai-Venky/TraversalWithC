// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
      
      map<int, set<int>> ans;
      vector<int> output;
      const int m = mat.size(), n = mat[0].size();

      for(int i=0;i<m;i++) {
        int l=0, h=n-1, m=0,ct=0;
        while(l<=h) {

          m=l+(h-l)/2;
          if(m==n-1 || mat[i][m] > mat[i][m+1]) {
            ct=m+1;
            break;
          } else if(mat[i][m]==0){
            h=m-1;
          } else {
            l=m+1;          
          }
        }
        ans[ct].insert(i);
      }
      
      for(auto val:ans) {
        output.insert(output.end(), val.second.begin(), val.second.end());
        if(output.size() > k) break;
      }
      return vector<int>(output.begin(), output.begin()+k);
      
    }
};