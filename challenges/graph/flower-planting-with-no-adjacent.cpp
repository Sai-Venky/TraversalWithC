// https://leetcode.com/problems/flower-planting-with-no-adjacent

class Solution {
public:  
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
      vector<int> o(n, 0);
      vector<vector<int>> e(n);
      for(auto path:paths) {
        e[path[0]-1].push_back(path[1]-1);
        e[path[1]-1].push_back(path[0]-1);
      }
      
      for(int i=0;i<n;i++) {
        unordered_set<int> s={1,2,3,4};
        for(int edge:e[i]) {
          if(o[edge]!=0) s.erase(o[edge]);
        }
        o[i]=*s.begin();
      };
      return o;
    }
};