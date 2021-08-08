// https://leetcode.com/problems/merge-intervals/

// Note use of Logic alone here for using sorting and back element alone

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end());
      vector<vector<int>> out = {intervals[0]};
      
      for(int i=1;i<intervals.size();i++) {
        if(intervals[i][0]>out.back()[1]) out.push_back(intervals[i]);
        else {
          out.back()[1]=max(out.back()[1], intervals[i][1]);
        }
      }
      
      return out;
    }
};
