// https://leetcode.com/problems/find-k-th-smallest-pair-distance

class Solution {
public:
    int smallestDistancePair(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int n = a.size(), lo = 0, hi = a[n-1] - a[0], ans = -1;
        while (lo <= hi) {
            int cnt = 0, j = 0, md = (lo + hi)/2;
            for (int i = 0; i < n; ++i) {
                while (j < n && a[j] - a[i] <= md) ++j;
                cnt += j - i-1;
            }
            if (cnt >= k) {
                ans = md;
                hi = md - 1;
            }
            else lo = md + 1;
        }
        
        return ans;
    }
};