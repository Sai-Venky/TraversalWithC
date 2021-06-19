// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = 0;
        for (int& i: left)
            res = max(res, i);
        for (int& i: right)
            res = max(res, n - i);
        return res;
    }
};