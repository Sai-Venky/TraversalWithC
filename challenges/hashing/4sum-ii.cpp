// https://leetcode.com/problems/4sum-ii

/* 
  Logic- Identify that the map can have duplicate sums, hence add them correspongingly in count and note its number of such sums.
  Code - Using map to store the sums.
*/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
      unordered_map<int, int> output;
      int ct=0;
        for(int i=0; i<A.size(); i++) {
          for(int j=0; j<B.size(); j++) {
            output[A[i] + B[j]]++;
          }
        }
      
        for(int i=0; i<C.size(); i++) {
          for(int j=0; j<D.size(); j++) {
            if(output.find(-C[i]-D[j])!=output.end()) {
              ct+=output[-(C[i]+D[j])];
            }
          }
        }
      return ct;
    }
};