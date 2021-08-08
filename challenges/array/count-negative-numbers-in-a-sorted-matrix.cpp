// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

// good coding question 

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;

        const int M = grid.size(), N = grid[0].size();
        int row = M-1, col = 0;
        int neg_count = 0;
        
        while(row >= 0 && col < N) {

            if(grid[row][col] < 0) {
                neg_count += N - col;
                --row;
            }
            else
                ++col;
        }
        return neg_count;
    }
};
