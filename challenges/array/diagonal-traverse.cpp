// https://leetcode.com/problems/diagonal-traverse

// Use map and Sf

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
      int m=mat.size(), n=mat[0].size();
      map<int, vector<int>> mp;
      
      for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
          mp[i+j].push_back(mat[i][j]);
        }
      }
      
      vector<int> out;
      int k=0;
      for(auto v:mp) {
        if(k++%2!=0) {
          for(int i=0;i<v.second.size();i++)
            out.push_back(v.second[i]);
        } else {
          for(int i=v.second.size()-1;i>=0;i--)
            out.push_back(v.second[i]);        
        }
        
      }
      
      return out;
    }
};