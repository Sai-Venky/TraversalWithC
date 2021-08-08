// https://leetcode.com/problems/maximum-ice-cream-bars

// SF

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
      
      sort(costs.begin(), costs.end());
      int maximum=0;
      
      for(int i=0;i<costs.size();i++) {
        
        coins-=costs[i];
        if(coins<0) break;
        maximum++;
      }
      
      return maximum;
    }
};