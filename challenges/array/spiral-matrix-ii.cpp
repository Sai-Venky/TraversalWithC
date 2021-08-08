// https://leetcode.com/problems/spiral-matrix-ii

// Note the traversals

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> output(n, vector<int> (n));
      int si=0, ei=n-1;
      int sj=0, ej=n-1;
      int k=1, i=si, j=sj;
      while(si<=ei) {
        for(j=sj;j<=ej;j++) {
          output[i][j] = k++;
        }
        j--;
        for(i=si+1;i<=ei;i++) {
          output[i][j] = k++;
        }
        i--;
        for(j=ej-1;j>=sj;j--) {
          output[i][j] = k++;
        }
        j++;
        for(i=ei-1;i>=sj+1;i--) {
          output[i][j] = k++;
        }
        i++;
        si++;ei--;
        sj++;ej--;
      }
      return output;
    }
};