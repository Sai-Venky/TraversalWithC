// https://leetcode.com/problems/binary-subarrays-with-sum/

/*
   c represents how many start-from-index-zero (prefix) sub array that sums to i.
   int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int, int> c({{0, 1}});
        int psum = 0, res = 0;
        for (int i : A) {
            psum += i;
            res += c[psum - S];
            c[psum]++;
        }
        return res;
    }
*/

/*
class Solution {
    public:
    int numSubarraysWithSum(vector<int>& a, int t) {
        int ans = 0;
        deque<int> dq;

        for(int i = 0, j = 0; i < a.size(); i++) {
            if(a[i] == 1) dq.push_back(i);
            if(dq.size() > t) j = dq.front() + 1, dq.pop_front();
            if(dq.size() == t) {
                if(dq.empty()) ans += (i-j+1);    //Edge case, simply evaluate the current window
                else ans += (dq.front()-j+1);
            }
        }
        return ans;
    }
};
*/

/*  
  Logic - Calculating the atmost logic here since this is case where solving for one subarray dose not generalize it for all subarrays
  Code  - Using Sliding Window
*/

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
