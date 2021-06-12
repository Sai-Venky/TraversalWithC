// https://leetcode.com/problems/minimum-number-of-refueling-stops


class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
      int m_stops=0, reached=0, fuel=startFuel, n=stations.size(), i=0;
      priority_queue<int> q;
      
      while(true) {
        reached+=fuel;
        while(i<n && stations[i][0]<=reached) {
          q.push(stations[i++][1]);
        }
        
        if(reached>=target) break;
        if(q.empty()) return -1;
        m_stops++;
        fuel = q.top();
        q.pop();
      }
      
      
      return m_stops;
    }
};
