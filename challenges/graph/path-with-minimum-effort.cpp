// https://leetcode.com/problems/path-with-minimum-effort

// Note the shortest path algorithms https://leetcode.com/problems/path-with-minimum-effort/discuss/909002/JavaPython-3-3-codes%3A-Binary-Search-Bellman-Ford-and-Dijkstra-w-brief-explanation-and-analysis.
/*
    DJIKSTRAS ALGORITHM
    O(m * n log(m * n)), space: O(m * n)
    class Solution {
        public:
        int minimumEffortPath(vector<vector<int>> &heights) {
            int m = heights.size(), n = heights[0].size();
            int dirs[5] = {-1, 0, 1, 0, -1};

            std::vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

            pq.emplace(0, 0); // First item is effort, second is row * 100 + col
            while (!pq.empty()) {
            int effort = pq.top().first;
            int x = pq.top().second / 100, y = pq.top().second % 100;
            pq.pop();

            if (x == m - 1 && y == n - 1) return effort;
            if (effort >= efforts[x][y]) continue;
            efforts[x][y] = effort;

            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i], ny = y + dirs[i + 1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                int n_effort = max(effort, abs(heights[x][y] - heights[nx][ny]));
                pq.emplace(n_effort, nx * 100 + ny);
            }
            }
            return -1;
        }
    };
*/

//  O(m * n * log(Max)), space: O(m * n)
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