// https://leetcode.com/problems/non-overlapping-intervals/

// Note use of single memeory and tracking one by one

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end());
      vector<int> latest = intervals[0];
      int ct=0;
      for(int i=1;i<intervals.size();i++) {
        if(intervals[i][0]>=latest[1]) latest=intervals[i];
        else {
          ct++;
          latest[1]=min(latest[1], intervals[i][1]);
        }
      }
      
      return ct;
    }
};