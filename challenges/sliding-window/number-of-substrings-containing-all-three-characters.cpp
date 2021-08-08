// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

/*  
  Logic - SF
  Code  - Sliding Window
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
      vector<int> v{0,0,0};
      int ct=0, j=0;
      for(int i=0; i<s.length();i++) {
        v[s[i] - 'a']++;
        while(v[0] && v[1] && v[2]) { v[s[j] - 'a']--;j++;}
        ct+=j;
      }
      return ct;
    }
};