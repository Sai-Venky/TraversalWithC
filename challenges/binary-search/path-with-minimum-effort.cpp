// https://leetcode.com/problems/path-with-minimum-effort

class Solution {
public:
    int m, n, mid;
    vector<int> x_points = {1, 0, -1, 0};
    vector<int> y_points = {0, 1, 0, -1};
    vector<vector<bool>> visited;  
  
    bool isValid(int x, int y) {
      return x < m and x >= 0 and y < n and y >= 0;
    }
  
    bool dfs(vector<vector<int>>& heights, int i, int j) {
      visited[i][j]=true;
      if(i==m-1 && j==n-1) {
        return true;
      }

      for (int k = 0; k < 4; k++) {
        int in = i + x_points[k];
        int jn = j + y_points[k];
        if(isValid(in, jn) && !visited[in][jn] && abs(heights[in][jn]-heights[i][j])<=mid) {
            if(dfs(heights, in, jn)) return true;
        }
      }
      return false;
    }
  
    int minimumEffortPath(vector<vector<int>>& heights) {
      m=heights.size();n=heights[0].size();
      int l=0, h=1e6;
      while(l<=h) {
        mid = l + ((h-l)/2);
        visited.assign(m,vector<bool> (n, false));
        if(!dfs(heights, 0, 0)) {
          l = mid+1;
        } else {
          h = mid-1;
        }
      }
      return l;
    }
};