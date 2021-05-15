// https://leetcode.com/problems/make-sum-divisible-by-p

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
      vector<int> A = nums;
      int n=A.size();
      A[0] = A[0]%p;
      for(int i=1;i<n;i++) {
        A[i]+=A[i-1];
        A[i] = A[i]%p;
      }
      if (A[n-1] == 0) return 0; 
      int ct=n;
      map<int, int> m;
      m[0]=-1;
      for(int i=0;i<n;i++) {
        m[A[i]] = i;
		    int diff = (A[i] - A[n-1] + p) % p;
        if(m.find(diff) != m.end()) {
          ct = min(ct, i-m[diff]);
        }
      }
      return ct < n ? ct : -1;
    }
};
