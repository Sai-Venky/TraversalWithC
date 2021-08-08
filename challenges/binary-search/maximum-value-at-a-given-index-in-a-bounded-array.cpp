// https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array

// https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/discuss/1119708/C%2B%2B-Binary-Search-O(log-n)
class Solution {
public:
   bool check(int n, int i, int maxSum, int m) {
    for (int d = 1; maxSum >= 0 && d < m && i + d < n; ++d)
        maxSum -= m - d;
    for (int d = 1; maxSum >= 0 && d < m && i - d >= 0; ++d)
        maxSum -= m - d;
    return maxSum >= 0;
  }
  int maxValue(int n, int index, int maxSum) {
      int l = 0, r = maxSum;
      while (l < r) {
          int m = (l + r + 1) / 2;
          if (check(n, index, maxSum - n - m, m))
              l = m;
          else
              r = m - 1;
      }
      return l + 1;
  }
};
