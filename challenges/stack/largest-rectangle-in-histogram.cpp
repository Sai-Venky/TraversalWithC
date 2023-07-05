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
            int maxi = 0;
            vector<int> tracker;
            int n=heights.size();
            heights.push_back(0);
            tracker.push_back(-1);
            for(int j=0;j<n+1;j++) {
                while(tracker.back()!=-1 && heights[tracker.back()] > heights[j]) {
                        int temp = tracker.back();
                        tracker.pop_back();
                        maxi = max(maxi, heights[temp] * (j-tracker.back()-1));
                }

                tracker.push_back(j);
            }

            return maxi;
    }
};