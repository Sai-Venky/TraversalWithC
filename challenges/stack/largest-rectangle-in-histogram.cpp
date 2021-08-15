// https://leetcode.com/problems/largest-rectangle-in-histogram

/*  
  Logic - SF
  Code  - Note the use of stack and addition of 0 in end to triiger computation in largestRectangleArea function
  Similar to maximal rectangle
  [2, 1, 5, 6, 2, 3]
  https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/452612/Thinking-Process-for-Stack-Solution
  https://abhinandandubey.github.io/posts/2019/12/15/Largest-Rectangle-In-Histogram.html
  When we reach the bar at position 4, we realize we can’t do a bar of height 6 anymore, so lets see what it can give us and pop it out.
  It is important to notice here how the elimination of 6 from stack has no effect on it being used to form the rectangle of height 5
*/

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