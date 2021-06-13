// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      heights.push_back(0);
      int n=heights.size(), mx=0;
      stack<int> s;
      
      for(int i=0;i<n;i++) {
        
        while(!s.empty() && heights[s.top()] >= heights[i]) {
          
          int h=heights[s.top()];
          s.pop();
          int w=s.size()>0 ? i-s.top()-1: i;
          mx=max(mx, h*w);
        }
        s.push(i);
      }
      
      return mx;
    }
};