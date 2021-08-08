// https://leetcode.com/problems/check-if-a-string-can-break-another-string/

class Solution {
public:
  bool checkIfCanBreak(string s1, string s2) {
    auto freq1 = charFreq(s1);
    auto freq2 = charFreq(s2);
    return canBreak(freq1, freq2) || canBreak(freq2, freq1);
  }
  
  vector<int> charFreq(const string& s) {
    vector<int> freq(26);
    for (char c : s)
      freq[c - 'a']++;
    return freq;
  }
  
  bool canBreak(const vector<int>& strong, const vector<int>& weak) {
    int diff = 0;
    for (int i = 25; i >= 0; --i) {
      diff += strong[i] - weak[i];
      if (diff < 0)
        return false;
    }
    return true;
  }
};