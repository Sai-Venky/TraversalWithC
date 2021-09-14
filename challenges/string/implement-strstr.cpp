// https://leetcode.com/problems/implement-strstr/

// Note KMP Basics here

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (!needle.length()) return 0;
        vector<int> lps = kmpProcess(needle);
        int n = haystack.length(), m = needle.length();
        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && haystack[i] != needle[j]) j = lps[j - 1];
            if (haystack[i] == needle[j]) {
                if (++j == m) return i - m + 1; // found solution
            }
        }
        return -1;
    }
private:
    vector<int> kmpProcess(string needle) {
        int n = needle.length();
        vector<int> lps(n, 0);
        for (int i = 1, j = 0; i < n; i++) {
            while (j > 0 && needle[i]!=needle[j]) j = lps[j - 1];
            if (needle[i]==needle[j]) lps[i] = ++j;
        }
        return lps;
    }
};