// https://leetcode.com/problems/minimum-area-rectangle/

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
      int out=INT_MAX;
      unordered_map<int, unordered_set<int>> m;
      
      for(auto point:points) {
        m[point[0]].insert(point[1]);
      }
      
      for(int i=0;i<points.size();i++) {
       for(int j=i+1;j<points.size();j++) {
         
          int x1 = points[i][0];
          int y1 = points[i][1];
          int x2 = points[j][0];
          int y2 = points[j][1];
          if ((x1 != x2) && (y2 != y1)) {
            if(m[x1].count(y2) && m[x2].count(y1)) {
              out=min(out, abs(y2-y1) * abs(x2-x1)) ;
            }
          }
         
        }   
      }
      
      return out==INT_MAX?0:out;
    }
};