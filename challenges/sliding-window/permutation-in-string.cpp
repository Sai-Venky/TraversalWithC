// https://leetcode.com/problems/permutation-in-string

// SF

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      vector<int> ct(26, 0);
      int j=0, l=s1.length();
      for(char c:s1) ct[c-'a']++;

      for(int i=0;i<s2.length();i++) {
        ct[s2[i]-'a']--;
        l--;
        while(ct[s2[i]-'a']<0) {
          ct[s2[j++]-'a']++;
          l++;
        }
        if(l==0) return true;
      }
      
      return false;
    }
};