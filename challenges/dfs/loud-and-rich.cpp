// https://leetcode.com/problems/loud-and-rich

class Solution {
public:
    int dfs(vector<vector<int>> &m, vector<int> &out, vector<int>& quiet, int k) {
      if(out[k]>=0) return out[k];
      
      int mini=quiet[k];
      out[k] = k;      
      
      for(int i=0;i<m[k].size();i++) {
          int index=dfs(m, out, quiet, m[k][i]);
          if(quiet[out[k]]>quiet[index]) {
          out[k] = index;      
        }
        
      }
      
      return out[k];
    }
  
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
      int n=quiet.size();
      vector<vector<int>> m(n);
      vector<int> out(n, -1);
      for(auto r:richer) {
        m[r[1]].push_back(r[0]);
      }
      
      for(int i=0;i<n;i++) {
        dfs(m, out, quiet, i);
      }
      
      return out;
    }
};