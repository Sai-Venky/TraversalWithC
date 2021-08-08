// https://leetcode.com/problems/k-closest-points-to-origin
/*
  Code  - SF
  Logic - Heap
*/
class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
      vector<vector<int>> output;
      for(int i=0;i<points.size();i++) {
        int dist = (points[i][1]*points[i][1])+(points[i][0]*points[i][0]);
        q.push(make_pair(dist, i));
      }
      
      while(k>0) {
        pair<int, int> p = q.top();
        q.pop();
        output.push_back(points[p.second]);
        k--;
      }
      
      return output;
    }
};