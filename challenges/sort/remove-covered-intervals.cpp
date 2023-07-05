// https://leetcode.com/problems/remove-covered-intervals/

/*
    Note the Optimization here.
    [[1,4],[1,5],[3,6],[2,8]]
    after sorting will be
    [[1,5],[1,4],[2,8],[3,6]]
    class Solution {
        public:
            static bool compare(const vector<int> &v1, const vector<int> &v2) {
            if(v1[0]==v2[0]) return v1[1]>v2[1];
                return v1[0]<v2[0];
            }
        
            int removeCoveredIntervals(vector<vector<int>>& in) {
            sort(in.begin(), in.end(), compare);
            int n=in.size();
            int ct=in.size();
            int prev=-1;
            for(int i=0;i<n;i++) {
                if(in[i][1]<=prev) ct--;
                prev=max(prev, in[i][1]);
            }
            return ct;
            }
};
    Sort and Find
*/

class Solution {
public:
    static bool compare(const vector<int> &v1, const vector<int> &v2) {
      if(v1[0]==v2[0]) return v1[1]>v2[1];
        return v1[0]<v2[0];
    }
  
    int removeCoveredIntervals(vector<vector<int>>& in) {
      sort(in.begin(), in.end(), compare);
      int n=in.size();
      int ct=in.size();
      for(int i=0;i<n;i++) {
        int left=
        for(int j=0;j<i;j++) {
          if(in[i][0]>=in[j][0] && in[i][1]<=in[j][1]) {
            ct--; break;
          }
        }
      }
      return ct;
    }
};