// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows

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
