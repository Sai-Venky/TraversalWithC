// https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix

class Solution {
public:
    
    int min = INT_MAX;
    
     bool isZeroMat(vector<vector<int>>& mat, int *m, int *n) {
        for(auto i = 0; i < *m; ++i)
            for(auto j = 0; j < *n; ++j)
                if(mat[i][j])
                    return false;
        return true;
    }
    
    void visitMatrix(vector<vector<int>> mat, int *m, int *n, vector<vector<int>> visited, int trav, int k, int l) {
        if(l!=-1) {
            mat[k][l] ^= 1;
            if(k - 1 >= 0) mat[k-1][l] ^= 1;
            if(k + 1 <  *m) mat[k+1][l] ^= 1;
            if(l - 1 >= 0) mat[k][l-1] ^= 1;
            if(l + 1 <  *n) mat[k][l+1] ^= 1;
        }
        
        if(isZeroMat(mat, m , n)) {
            min = trav;
            return;
        }
        
        for(int i=0; i<*m; i++) {
            for(int j=0; j<*n; j++) {
                if(visited[i][j] == 0) {
                    visited[i][j] = 1;
                    visitMatrix(mat, m, n, visited, trav+1, i, j);
                    if(min!=10000) return;
                    visited[i][j] = 0;
                }
            }
        }
    }
    
    
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> visited( m , vector<int> (n, 0));  
        
        visitMatrix(mat, &m, &n, visited, 0, -1, -1);
        
        if(min!=INT_MAX) {
            return min;
        } else {
            return -1;
        }
    }
};