// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows

/*

    class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        int ans = 0;
        int m = matrix.length, n = matrix[0].length;
        for(int i = 0; i < m; i++) {
            int cnt = 0;
            int[] flip = new int[n];
            for(int j = 0; j < n; j++) flip[j] = 1 - matrix[i][j];
            for(int k = i; k < m; k++) {
                if(Arrays.equals(matrix[k], matrix[i]) || Arrays.equals(matrix[k], flip)) cnt++;
            }
            ans = Math.max(ans, cnt);
        }
        return ans;
    }
    }
     Note the use of Relative Ordering here.
*/
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
      int ct=0;
      unordered_map<string, int> m;
      for(vector<int> row:matrix) {
        
        string s="";
        int tp=row[0];
        for(int i=0;i<row.size();i++) {
          s+=tp==row[i]?'1':'0';
        }
        m[s]++;
      }
      for(auto v:m) {
        ct=max(ct, v.second);
      }
      
      return ct;
    }
};
