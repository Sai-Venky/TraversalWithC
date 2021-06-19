// https://leetcode.com/problems/merge-strings-alternately

class Solution {
public:
    string mergeAlternately(string a, string b) {
        int i = 0, j = 0, M = a.size(), N = b.size();
        string ans;
        while (i < M || j < N) {
            if (i < M) ans += a[i++];
            if (j < N) ans += b[j++];
        }
        return ans;
    }
};