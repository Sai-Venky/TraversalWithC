// https://leetcode.com/problems/shortest-path-with-alternating-colors

// Note the use of the second element.

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& re, vector<vector<int>>& be) {
      map<int, vector<int>> r;
      map<int, vector<int>> b;
      map<int, int> m;
      set<pair<int, bool>> v;
      queue<pair<int, bool>> q;
      
      for(auto e:re) {
        r[e[0]].push_back(e[1]);
      }
      for(auto e:be) {
        b[e[0]].push_back(e[1]);
      }
      
      vector<int> out;
      out.push_back(0);
      int l=0;
      q.push({0, true});
      q.push({0, false});
      
      while(!q.empty()) {
        int  sz=q.size();
        for(int i=0;i<sz;i++) {
          pair<int, bool> p=q.front(); 
          q.pop();
          vector<int> t;
          if(v.count({p.first, p.second})) continue;
          v.insert({p.first, p.second});
          if(p.second) t=b[p.first];
          else t=r[p.first];

          for(int e:t) {
            q.push({e, !p.second});
          }
          if(m[p.first]==0) m[p.first]=l;
          else m[p.first] = min(m[p.first], l);
        }
        l++;
      }
      
      for(int i=1;i<n;i++) {
        out.push_back(m[i]==0?-1:m[i]);
      }
        
      
      return out;
    }
};