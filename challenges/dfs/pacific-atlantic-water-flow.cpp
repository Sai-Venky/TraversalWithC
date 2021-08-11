// https://leetcode.com/problems/pacific-atlantic-water-flow


/*
    Logic - Note the use of DFS. Finding the places where surroundings in 4 directions are lower than its current value
    Code - SF
*/

class Solution {
public:
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& v, int i, int j, int height) {
        if (i < 0 || i > grid.size()-1 || j < 0 || j > grid[0].size()-1 || v[i][j]) return;
        if (grid[i][j] < height) return;
        v[i][j] = true;
        for (int k=0; k<4; k++) {
            dfs(grid, v, i+dx[k], j+dy[k], grid[i][j]);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        if (!matrix.size()) return ans;
        vector<vector<bool>> v1(matrix.size(), vector<bool>(matrix[0].size(), false));
        vector<vector<bool>> v2(matrix.size(), vector<bool>(matrix[0].size(), false));
        for (int i=0; i<matrix.size(); i++) {
            dfs(matrix, v1, i, 0, INT_MIN);
            dfs(matrix, v2, i, matrix[0].size()-1, INT_MIN);
        }
        for (int j=0; j<matrix[0].size(); j++) {
            dfs(matrix, v1, 0, j, INT_MIN);
            dfs(matrix, v2, matrix.size()-1, j, INT_MIN);
        }
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[0].size(); j++) {
                if (v1[i][j] && v2[i][j]) {
                    vector<int> temp{i, j};
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};

