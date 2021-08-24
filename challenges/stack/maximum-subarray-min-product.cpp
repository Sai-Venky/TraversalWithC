// https://leetcode.com/problems/maximum-subarray-min-product

/*
    Counting the number of subarrays that have that element as minimum
    vector <int> CountSubarrays(vector <int> arr) {
        int n = arr.size();
        vector<int> left(n, 0); //number of subarrays ending at i of len > 1
        vector<int> right(n, 0); //number of subarrays starting at i of len > 1
        vector<int> res(n, 0);
        
        stack<int> s;
        s.push(0);
        for(int i=1;i<n;i++){
            
            while(!s.empty() && arr[s.top()]<arr[i]){
            s.pop();
            }
            int nextGreaterIdx = s.empty() ? -1 : s.top();
            left[i] = i-nextGreaterIdx-1;
            s.push(i);
        }
        
        stack<int> s2;
        s2.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!s2.empty() && arr[s2.top()]<arr[i]){
            s2.pop();
            }
            int nextGreaterIdx = s2.empty() ? n : s2.top();
            right[i] = nextGreaterIdx-i-1;
            s2.push(i);
        }
        
        for(int i=0;i<n;i++){
            res[i] = left[i]+right[i]+1; // +1 for subarray of size 1
        }
        
        return res;
    
    }
*/

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
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int mod = 1000000007;
        int n = nums.size(), lft[n], rgt[n];
        long long int sum[n + 1];
        sum[0] = nums[0];
        for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + nums[i];
      
        vector<int> s1;
        for(int i=0;i<n;i++) {
          
          while(!s1.empty() && nums[s1.back()] >= nums[i] ) s1.pop_back();
          int l=s1.size()>0?s1.back():-1;
          lft[i] = i-l-1;
          s1.push_back(i);
        }
        s1.clear();
      
        for(int i=n-1;i>=0;i--) {
          
          while(!s1.empty() && nums[s1.back()] >= nums[i] ) s1.pop_back();
          int l=s1.size()>0?s1.back():n;
          rgt[i] = l-i-1;
          s1.push_back(i);
        }
        long long int ans = 0;
        for(int i=0;i<n;i++) {
          ans=max(ans, (nums[i] * (nums[i-lft[i]]+sum[i+rgt[i]] - sum[i-lft[i]])));
        }

        return ans % mod;           
    }

};
