// https://leetcode.com/problems/subarrays-with-k-different-integers

class Solution {
public:
    int atMost(vector<int>& A, int k) {
      int i=0, ct=0, sum=0;
      unordered_map<int, int> m;
      for (int j=0;j<A.size();j++) {
        if(m[A[j]]++==0) k--;
        while(k<0) {
          --m[A[i]];
          if(m[A[i]]==0) k++;
          i++;
        }
        ct+=(j-i+1);
      }
      
      return ct;
    }
  
    int subarraysWithKDistinct(vector<int>& A, int K) {
      return atMost(A, K) - atMost(A, K-1);
    }
};