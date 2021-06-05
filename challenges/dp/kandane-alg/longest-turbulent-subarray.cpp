// https://leetcode.com/problems/longest-turbulent-subarray

/*
    Let's define

    state[i]: longest turbulent subarray ending at A[i]

    state transition relies on the comparison sign between A[i - 1] and A[i], so

    state[i][0]: longest turbulent subarray ending at A[i] and A[i-1] < A[i]
    state[i][1]: longest turbulent subarray ending at A[i] and A[i-1] > A[i]

    state transition is

    state[i][0] = state[i - 1][1] + 1 or 1
    state[i][1] = state[i - 1][0] + 1 or 1
*/

// With DP
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
      int n=arr.size();
      vector<vector<int>> dp(n+1, vector<int>(2, 0));
      int m=0;
      for(int i=1;i<n;i++) {
        if(arr[i] > arr[i-1]) {
          dp[i][0] = dp[i-1][1] + 1;
          m=max(m, dp[i][0]);
        } else if (arr[i] < arr[i-1]){
          dp[i][1] = dp[i-1][0] + 1;
          m=max(m, dp[i][1]);
        }
      }
      return m+1;
    }
};

// From DP
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
      int n=arr.size();
      int m=0;
      int increase=0, decrease=0;
      for(int i=1;i<n;i++) {
        if(arr[i] > arr[i-1]) {
          increase=decrease+1;
          decrease=0;
          m=max(m, increase);
        } else if (arr[i] < arr[i-1]){
          decrease=increase+1;
          increase=0;
          m=max(m, decrease);
        } else {
          increase=0;
          decrease=0;
        }
      }
      return m+1;
    }
};