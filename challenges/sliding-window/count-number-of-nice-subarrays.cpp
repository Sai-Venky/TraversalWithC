// https://leetcode.com/problems/count-number-of-nice-subarrays/


/*
    int numberOfSubarrays(vector<int>& A, int k) {
        return atMost(A, k) - atMost(A, k - 1);
    }

    int atMost(vector<int>& A, int k) {
        int res = 0, i = 0, n = A.size();
        for (int j = 0; j < n; j++) {
            k -= A[j] % 2;
            while (k < 0)
                k += A[i++] % 2;
            res += j - i + 1;
        }
        return res;
    }
*/

/*  
  Logic - Calculating the atmost logic here since this is case where solving for one subarray dose not generalize it for all subarrays.
          Here q[1] - q[0] counts all subarrays ending at q[1], since its applicable for all sub arrays between those.
  Code  - Using Sliding Window
*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
      int ct=0, n=nums.size();
      deque<int> q = {-1};
      
      for(int i=0; i<nums.size(); i++) {
        if(nums[i] % 2) q.push_back(i);
        if(q.size() > k+1) q.pop_front();
        if(q.size() == k+1) ct+=q[1] - q[0];
      }
      return ct;
    }
};