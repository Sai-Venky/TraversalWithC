// https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/

class Solution {
public:
  int maximumSum(vector<int>& arr) {
    int n = arr.size(), res = arr[0];
    vector<int> keep(n), del(n);

    keep[0] = del[0] = arr[0];
    cout<<keep[0]<<" "<<del[0]<<"\n";
    
    for (int i = 1; i < n; i++) {
      keep[i] = max(keep[i - 1], 0) + arr[i]; 
      del[i] = max(keep[i - 1], del[i - 1] + arr[i]);
      cout<<keep[i]<<" "<<del[i]<<"\n";
      res = max({ res, keep[i], del[i] });
    }
    return res;
  }
};