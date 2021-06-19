// https://leetcode.com/problems/rotate-image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        for (int i = 0; i < matrix.size() / 2; i++) {
            
            int start = i, end = matrix.size() - i - 1;
            
            for(int j = 0; j < end - start; j++) {
                int temp = matrix[start][start + j];        
                matrix[start][start + j] = matrix[end - j][start];
                matrix[end - j][start] = matrix[end][end - j];
                matrix[end][end - j] = matrix[start + j][end];
                matrix[start + j][end] = temp;
                
            }
            
        }
        
    }
};