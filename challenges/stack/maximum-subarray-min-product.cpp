// https://leetcode.com/problems/maximum-subarray-min-product

class Solution {
public:
    int maxSumMinProduct(vector<int>& n) {
      long res = 0;
      vector<long> dp(n.size() + 1), st;
      
      for (int i = 0; i < n.size(); ++i)
         dp[i + 1] = dp[i] + n[i];

      for (int i = 0; i <= n.size(); ++i) {
          while (!st.empty() && (i == n.size() || n[st.back()] > n[i])) {
              int j = st.back();
              st.pop_back();
              res = max(res, n[j] * (dp[i] - dp[st.empty() ? 0 : st.back() + 1]));
          }
          st.push_back(i);
      }
      return res % 1000000007;
    }
  
};

/*  
    Logic - Calculate the left and right stack as to how many elements are greater and lesser for each
    Code - Stack
*/
public:
    int maxSumMinProduct(vector<int>& nums) {
        int mod = 1000000007;
        int n = nums.size();
        int lft[n], rgt[n];
        long long int sum[n + 1];
        sum[0] = 0;
        for (int i = 1; i < n + 1; i++)
        {
            sum[i] = sum[i - 1] + nums[i - 1];
        }

        stack<pair<int, int>> s1, s2;        
        lft[0] = 0;
        s1.push({nums[0], 0});
        for (int i = 1; i < n; i++)
        {
            int cur = 0;
            while(!s1.empty() && (s1.top().first) >= nums[i])
            {
                cur += s1.top().second + 1;
                s1.pop();
            }
            s1.push({nums[i], cur});
            lft[i] = cur;
        }
        
        rgt[n - 1] = 0;
        s2.push({nums[n - 1], 0});
        for (int i = n - 2; i > -1; i--)
        {
            int cur = 0;
            while(!s2.empty() && (s2.top().first) >= nums[i])
            {
                cur += s2.top().second + 1;
                s2.pop();
            }
            s2.push({nums[i], cur});
            rgt[i] = cur;
        }

        long long int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, nums[i] * (sum[i + rgt[i] + 1] - sum[i - lft[i]]));
        }
        return ans % mod;           
    }
