// https://leetcode.com/problems/two-city-scheduling/

// Note the use of relative calculations

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
      int cost=0;
      int n=costs.size()/2;
      multimap<int, int> m;
            
      for(int i=0;i<2*n;i++) {
        m.insert(pair <int, int> (costs[i][0]-costs[i][1],i));
      }
      int k=0;
      for(auto v:m) {
        if(k++<n) {
          cost+=costs[v.second][0];
        } else {
          cost+=costs[v.second][1];          
        }
      }
        
      return cost;
  }
};