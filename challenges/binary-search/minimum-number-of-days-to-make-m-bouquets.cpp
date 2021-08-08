// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

/*
  Code - BS
  Logic - The monotonicity of this problem is very clear: if we can make m bouquets after waiting for d days, then we can definitely finish that as well if we wait more than d days.
  If we can discover some kind of monotonicity, for example, if condition(k) is True then condition(k + 1) is True, then we can consider binary search.

*/

bool canHarvest(vector<int>& bDay, int harvestDay, int m, int k) {
    int adjacent = 0;
    for (auto bloomDay : bDay) {
        adjacent = bloomDay <= harvestDay ? adjacent + 1 : 0;
        if (adjacent == k) {
            adjacent = 0;
            --m;
        }
    }
    return m <= 0;
}
int minDays(vector<int>& bDay, int m, int k) {
    if (m * k > bDay.size())
        return -1;
    auto lo = 1, hi = 1000000000;
    while (lo < hi) {
        auto mid = (hi + lo) / 2;
        if (canHarvest(bDay, mid, m, k))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}