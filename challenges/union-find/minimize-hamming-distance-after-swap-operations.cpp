// https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations

class Solution {
public:
    int find(vector<int> &parent, int x) {
      if(parent[x]==x) return x;
      parent[x]=find(parent, parent[x]);
      return parent[x];
    }
  
    void uni(vector<int> &parent, int x, int y) {
      int u=find(parent, x);
      int v=find(parent, y);
      if(u!=v) parent[u]=v;
    }
  
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
      int n=source.size(),out=0;
      vector<int> parent(n,-1);

      for (int i = 0; i < n; i++) parent[i] = i;
      unordered_map<int, unordered_multiset<int>> m;
      
      for(auto allowedSwap:allowedSwaps) uni(parent, allowedSwap[0], allowedSwap[1]);

      for(int i=0;i<parent.size();i++) {
        m[find(parent, i)].insert(source[i]);
      }
      
      for (int i = 0; i < n; i++) {
        if (!m[parent[i]].count(target[i]))
            out++;
        else
            m[parent[i]].erase(m[parent[i]].find(target[i]));
      }

      
      return out;
    }
};