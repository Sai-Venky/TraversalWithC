// https://leetcode.com/problems/find-right-interval

/*
    Note the use of binary search to find the lower bound.
*/

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
      vector<int> out;
      map<int, int> m;
      
      for(int i=0;i<intervals.size();i++) m[intervals[i][0]]=i;
      
      for(int i=0;i<intervals.size();i++) {
        auto find = m.lower_bound(intervals[i][1]);
        if (find == m.end()) out.push_back(-1);
        else out.push_back(find->second);
      }      
      
      
      return out;
    }
};