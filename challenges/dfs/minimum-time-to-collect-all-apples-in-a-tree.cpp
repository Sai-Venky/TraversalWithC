// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

class Solution {
public:
    vector<int> v;
    
    int dfs(unordered_map<int, vector<int>> &m, vector<bool>& a, int n, vector<bool>& vis) {
      int ct=0;
      if(vis[n]) return 0;
      vis[n]=true;
      for(int i=0;i<m[n].size();i++) {
        ct+=dfs(m, a, m[n][i], vis);
      }      
      if(n!=0 && (a[n] == true || ct>0)) {
        ct+=2;
      }
      return ct;
      
    }
    
    int minTime(int n, vector<vector<int>>& e, vector<bool>& a) {
      vector<bool> vis(n, false);
      unordered_map<int, vector<int>> m;
      
      for (auto _e:e) {
        m[_e[0]].push_back(_e[1]);
        m[_e[1]].push_back(_e[0]);
      }
      v.push_back(0);
      
      return dfs(m, a, 0, vis);
      
      
    }
};