// https://leetcode.com/problems/number-of-boomerangs/

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
      
      unordered_map<int, int> m;
      int out=0;
      for(int i=0;i<points.size();i++) {
        for(int j=0;j<points.size();j++) {          
          int d=(points[i][0]-points[j][0])*(points[i][0]-points[j][0]) + (points[i][1]-points[j][1])*(points[i][1]-points[j][1]);
          m[d]++;
        }
        for (auto& p : m) {
          out += p.second * (p.second - 1);
        }
        m.clear();
      }
      
      return out;
    }
};