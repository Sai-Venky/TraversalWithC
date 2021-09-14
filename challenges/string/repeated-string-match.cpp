// https://leetcode.com/problems/repeated-string-match

// Note the good coding style of final loop and use of percent here and leveraging j length to handle cases. 
// It also handles if no characters match 

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
      int ct=0;
      vector<int> lps(b.length(), 0);
      
      for(int i=1, j=0;i<b.length();i++) {
        while(j>0 && b[i]!=b[j]) j=lps[j-1];
        if (b[i]==b[j]) lps[i] = ++j;
      }
      
      for (auto i = 0, j = 0; i < a.size(); i++, j = j ? lps[j-1] : 0) {
        while (j < b.size() && a[(i + j) % a.size()] == b[j])
            ++j;
        if (j == b.size())
            return ceil((float)(i + j) / a.size());
      }
      
      return -1;
    }
};