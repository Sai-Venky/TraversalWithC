// https://leetcode.com/problems/minimum-number-of-refueling-stops


class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
      int m_stops=0, reached=0, fuel=startFuel;
      priority_queue<int> q;
      
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> des;
      
      for(auto station: stations) {
        des.push({station[0], station[1]});
      }
      
      while(true) {
        reached+=fuel;
        while(!des.empty() && des.top().first<=reached) {
          q.push(des.top().second);
          des.pop();
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

