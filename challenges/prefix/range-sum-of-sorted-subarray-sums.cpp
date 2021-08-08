// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

/*
  int rangeSum(vector<int>& nums, int n, int left, int right) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mqueue;
    for (int i=0; i<n; i++)
      mqueue.push({nums[i], i+1});

    int ans = 0, mod = 1e9+7;
    for (int i=1; i<=right; i++) {
      auto p = mqueue.top();
      mqueue.pop();
      if (i >= left)
        ans = (ans + p.first) % mod;
      if (p.second < n) {
        p.first += nums[p.second++];
        mqueue.push(p);
      }
    }
    return ans;
  }
*/

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
      vector<long> roll(n+1, 0);
      multiset<long> result;

      long s=nums[0];
      for(int i=1;i<n+1;i++) {
        roll[i] += s + roll[i-1];
        s = nums[i];
      }
      
      for(int i=1;i<n+1;i++) {
        int k=0;
        while(k<i) {
          result.insert(roll[i] - roll[k++]);
        }
      }
      long sum=0;
      int i=1;
      for (auto itr: result){
        if(i>=left&&i<=right)
          sum+=itr;
        i++;
      }
      return sum % 1000000007;
      
      
    }
};