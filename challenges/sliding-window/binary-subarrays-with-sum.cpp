// https://leetcode.com/problems/binary-subarrays-with-sum/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        return atMost(A, S) - atMost(A, S - 1);
    }

    int atMost(vector<int>& A, int k) {
      int i=0, ct=0, sum=0;
      if (k<0) return 0;
      for (int j=0;j<A.size();j++) {
        sum+=A[j];
        while(sum>k) {
          sum-=A[i];
          i++;
        }
        ct+=(j-i+1);
      }
      
      return ct;
    }
};