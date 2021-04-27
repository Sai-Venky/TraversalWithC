// https://leetcode.com/problems/find-center-of-star-graph

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
      int a=0,b=0;
      for(auto edge:edges) {
        if(a == edge[0] || a == edge[1]) return a;
        if(b == edge[0] || b == edge[1]) return b;
        a = edge[0];
        b = edge[1];
      }
      return 0;
    }
};