// https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid

/*
  Logic -
    Using coloring and BFS backward check
  Code -
    DFS AND BFS
*/

/*
NICE Note the reconstruction of array here.
https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/discuss/547225/C%2B%2B-with-picture%3A-track-direction-%2B-upscaled-grid
class Solution {
public:
    bool dfs(vector<vector<bool>> &g, int i, int j) {
    if (min(i, j) < 0 || i >= g.size() || j >= g[i].size() || !g[i][j])
        return false;
    if (i == g.size() - 2 && j == g[i].size() - 2)
        return true;
    g[i][j] = false;
    return dfs(g, i - 1, j) || dfs(g, i + 1, j) || dfs(g, i, j + 1) || dfs(g, i, j - 1);
}
    bool hasValidPath(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> g(m * 3, vector<bool>(n * 3));
    for (auto i = 0; i < m; ++i)
        for (auto j = 0; j < n; ++j) {
            auto r = grid[i][j];
            g[i * 3 + 1][j * 3 + 1] = true;
            g[i * 3 + 1][j * 3 + 0] = r == 1 || r == 3 || r == 5;
            g[i * 3 + 1][j * 3 + 2] = r == 1 || r == 4 || r == 6;
            g[i * 3 + 0][j * 3 + 1] = r == 2 || r == 5 || r == 6;
            g[i * 3 + 2][j * 3 + 1] = r == 2 || r == 3 || r == 4;
        }
    return dfs(g, 1, 1);    
}
};
*/

// going to all possible next locations from current and checking if we can come back from that next location
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> directs({
            {{0, -1}, {0, 1}},
            {{-1, 0}, {1, 0}},
            {{0, -1}, {1, 0}},
            {{0, 1}, {1, 0}},
            {{0, -1}, {-1, 0}},
            {{0, 1}, {-1, 0}}
        });

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<vector<int>> bfs;
        bfs.push({0, 0});
        visited[0][0] = true;
        while (!bfs.empty()) {
            vector<int> cur = bfs.front();
            bfs.pop();

            int row = cur[0];
            int col = cur[1];
            int type = grid[row][col] - 1;
            for (auto& dir : directs[type]) {
                int nr = row + dir[0];
                int nc = col + dir[1];
                if (nr < 0 or nr >= m or nc < 0 or nc >= n or visited[nr][nc]) {
                    continue;
                }

                for (auto& backDir : directs[grid[nr][nc] - 1])
                    if (nr + backDir[0] == row and nc + backDir[1] == col) {
                        visited[nr][nc] = true;
                        bfs.push({nr, nc});
                    }
            }
        }
        return visited[m - 1][n - 1];
    }
};
