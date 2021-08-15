// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

/*
    Note the use of count  and then recursion here to restrict and compute the outpus
*/

class Solution {
  public:
     int longestSubstring(string s, int k) {
        int n = (int)s.length();
        unordered_map<char, int> count;
        for (char c : s) ++count[c];
        int mid = 0;
        while (mid < n && count[s[mid]] >= k) ++mid;
        if (mid == n) return n;
        int left = longestSubstring(s.substr(0, mid), k);
        // Note the optimization here.
        while (mid < n && count[s[mid]] < k) ++mid;
        int right = longestSubstring(s.substr(mid), k);
        return max(left, right);
    }
};

