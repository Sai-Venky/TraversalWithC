// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/

// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/discuss/720313/C%2B%2B-Python-Java-Beautiful-Visual-Explanation

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