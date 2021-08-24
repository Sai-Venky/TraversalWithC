// https://leetcode.com/problems/restore-the-array

/*
Our base case is pretty simple dp[N - 1] = s[N - 1] fullfill conditions ? 1 : 0. 
The induction rule is slightly more complicated.
Suppose dp[i] satisfy the conditions, this means that we can restore the array as [s[i], ...]. 
How many ways can we do this? The answer is dp[i + 1], since it represent the maximum number of times we can rearrange the ... part. 
If dp[i] does not satisfy the conditions, then it is simply 0. We are not done yet. 
Notice that we can also return the array as [s[i : i + 1], ...] and [s[i : i + 2], ...] and so on until either s[i : j] > k or j == N. 
For each of these case, we can add dp[j + 1] to dp[i] using the same logic. 
Finally, remeber to modulo dp[i] after each iteration to prevent overflow.

*/

class Solution {
public:
    int numberOfArrays(string s, int k) {
      int n=s.length();
      vector<long> dp(n+1, 0);
      dp[n]=1;
      
      for(int i=n-1;i>=0;i--) {
        long sum=0;
        for(int j=i;j<n;j++) {
          
          sum=sum*10+(s[j]-'0');
          if(sum==0||sum>k) break;
          else {
            dp[i]+=dp[j+1];
          }
          
        }
        dp[i] %= 1000000007;
      }
      
      return dp[0];
    }
};


