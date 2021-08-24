// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

// Note the use of logic here.
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
      int res=0, end=INT_MAX;
      sort(points.begin(), points.end());
      
      for(int i=0;i<points.size();i++) {
        if(points[i][0] >end) {
          res++;
          end=points[i][1];
        } else end = min(end, points[i][1]);
        
      }
      
      return res + 1;
    }
};