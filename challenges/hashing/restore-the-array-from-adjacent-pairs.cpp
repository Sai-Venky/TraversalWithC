// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& ap) {
      
      int n=ap.size()+1, cur;
      map<int, vector<int>> m;
      vector<int> out(n, -1);
      
      for(auto a:ap) {
        m[a[0]].push_back(a[1]);
        m[a[1]].push_back(a[0]);
      }

      for(auto v:m) {
        if(v.second.size()==1) {
          out[0]=v.first;
          cur=v.second[0];
          break;
        }
      }
      
      for(int i=1;i<n;i++) {
        out[i]=cur;
        cur = m[cur][0]==out[i-1] && m[cur].size()==2?m[cur][1]:m[cur][0];
      }

      return out;
    }
};
