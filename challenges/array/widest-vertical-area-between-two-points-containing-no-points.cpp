// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points

// SF

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
      
      sort(points.begin(), points.end());
      int prev=points[0][0], diff=0;
      for(int i=1;i<points.size();i++) {
        
        if(points[i][0] == prev) continue;
        
        diff=max(diff, points[i][0]-prev);
        prev=points[i][0];
        
      }
      return diff;
    }
};