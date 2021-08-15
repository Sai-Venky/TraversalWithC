// https://leetcode.com/problems/score-after-flipping-matrix/

// Note the use of logic and math here

/*
https://leetcode.com/problems/score-after-flipping-matrix/discuss/143812/C%2B%2BJava-From-Intuition-Un-optimized-code-to-Optimized-Code-with-Detailed-Explanation
    class Solution {
        public int matrixScore(int[][] A) {
            int m = A.length;
            int n = A[0].length;
            int result = 0;
            
            result += (1 << (n-1))*m;
            
            for(int j = 1;j < n;j++){
                int same = 0;
                for(int i = 0;i < m;i++){
                     // Note this line's logic here 
                    if(A[i][0] == A[i][j])
                        same++;
                }
                // Note this line's optimization 
                result += (1 << (n-1-j))*Math.max(same,m-same);
            }
            
            return result;
        }
    }
*/

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
      
      vector<string> dp;
      for(int i=0;i<grid.size();i++) {
        string s="";
        for(int j=0;j<grid[i].size();j++) {
          s.push_back('0' + grid[i][j]);
        }
        dp.push_back(s);
      }
      
      for(int i=0;i<dp.size();i++) {
        if(dp[i][0]=='0') {
          for(int j=0;j<dp[i].length();j++) {
            if(dp[i][j]=='0') dp[i][j]='1';
            else dp[i][j]='0';
          }
        }
      }
      
      for(int j=1;j<grid[0].size();j++) {
        int onect=0, zeroct=0;
        for(int i=0;i<grid.size();i++) {
          if(dp[i][j]=='1') onect++;
          else zeroct++;
        }
        if(zeroct>onect) {
          for(int i=0;i<dp.size();i++) {
            if(dp[i][j]=='0') dp[i][j]='1';
            else dp[i][j]='0';
          }
        }
      }
      
      int out=0;
      
      for(string s:dp) {
        cout<<s<<endl;
        out+=stoi(s, 0, 2);
      }
      
      return out;
    }
};

