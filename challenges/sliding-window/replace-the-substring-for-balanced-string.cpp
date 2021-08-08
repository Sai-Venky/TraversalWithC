// https://leetcode.com/problems/replace-the-substring-for-balanced-string

/*  
  Logic - Note the use of map here. We computer each character count in prefix. Then delete one by one and try to find the count.
  Code  - Sliding Window
*/

class Solution {
public:
    int balancedString(string s) {
      map<char, int> mp;
      for(auto c:s) mp[c]++;
      int n = s.length()/4;
      int j=0;
      int window = s.length();
      for(int i=0;i<s.length();i++){
        mp[s[i]]--;
        while(mp['Q'] <= n && mp['W'] <= n && mp['E'] <= n && mp['R'] <= n && s.length()>j) {
          mp[s[j]]++;
          window=min(window, i-j+1);
          j++;
        }
      }
      return window;
    }
};
