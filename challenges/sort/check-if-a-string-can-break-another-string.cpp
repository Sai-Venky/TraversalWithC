// https://leetcode.com/problems/check-if-a-string-can-break-another-string/

/*
  NOte the use if trick here where total always greater than or lesser than another string
  bool checkIfCanBreak(string s1, string s2) {
    vector<int> v(26, 0);
    
    // count characters in s1 and s2, 
    // positive for char in s1 and negative for char in s2
    for (int i = 0; i < s1.size(); ++i) {
      ++v[s1[i] - 'a'];
      --v[s2[i] - 'a'];
    }
    
    bool s1s2 = true, s2s1 = true;
    int total = 0;
    
    for (int val : v) {
      total += val;
      
      // if s1 can break s2, total always >= 0
      // if s2 can break s1, total always <= 0
      if (total < 0) s1s2 = false; 
      if (total > 0) s2s1 = false;
      if (!s1s2 && !s2s1) return false;
    }
    
    return true;
  }
*/
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

