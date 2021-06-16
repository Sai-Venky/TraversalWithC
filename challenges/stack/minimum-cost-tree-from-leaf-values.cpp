// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values

/*
class Solution {
public:
    int mctFromLeafValues(vector<int>& A) {
        int res = 0;
        vector<int> stack = {INT_MAX};
        for (int a : A) {
            while (stack.back() <= a) {
                int mid = stack.back();
                stack.pop_back();
                res += mid * min(stack.back(), a);
            }
            stack.push_back(a);
        }
        for (int i = 2; i < stack.size(); ++i) {
            res += stack[i] * stack[i - 1];
        }
        return res;
    }
};
*/

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
      int n=arr.size(), sum=0;
      vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
      vector<vector<int>> mx(n, vector<int>(n, 0));
      
      for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
          if(i==j) mx[i][j] = arr[j];
          else mx[i][j] = max(mx[i][j-1], arr[j]);
        }
      }
      
      for(int i=0;i<n;i++) dp[i][i]=0;
   
      for(int i=1;i<n;i++) {
        dp[i-1][i]=(arr[i] * arr[i-1]);
      }
      
      for(int l=2;l<n;l++) {
        
        for(int s=0;s<n-l;s++) {
          int e=s+l;
          
          for(int k=s;k<e;k++) {
            dp[s][e] = min(dp[s][e], dp[s][k] + dp[k+1][e] + (mx[s][k] * mx[k+1][e]));
          }
        }
      }
      return dp[0][n-1];
      
      
      
    }
};