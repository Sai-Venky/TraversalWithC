// https://leetcode.com/problems/non-decreasing-array/

class Solution {
public:
    bool checkPossibility(vector<int>& a) {
      int modified = 0;
      for (int i = 1; i < a.size(); i++) {
          if (a[i] < a[i - 1]) {
              if (++modified>1) return false;
              (i - 2 < 0 || a[i - 2] <= a[i]) ? a[i - 1] = a[i] : a[i] = a[i - 1];
          }
      }
      return true;
    }
};