// https://leetcode.com/problems/find-all-anagrams-in-a-string

/*
    Code - SW
    Logic - SF 2 arrays storing
    vector<int> findAnagrams(string s, string p) {
	vector<int> goal(26), cur(26), res;
	for(char c : p) goal[c - 'a']++;
	for(int i = 0; i < s.size(); i++) {
		cur[s[i] - 'a']++;
		if(i >= p.size()) cur[s[i - p.size()] - 'a']--;
		if(cur == goal) res.push_back(i - p.size() + 1);
	}
	return res;
}
*/


class Solution {
public:
    bool validate(vector<int>& count_s, vector<int>& count_p) {
      for(int i=0;i<26;i++) {
        if(count_s[i]!=count_p[i]) {
          return false;
        }
      }
      return true;
    }
  
    vector<int> findAnagrams(string s, string p) {
      vector<int> out;
      int n=s.length(), m=p.length(), l=0, h=0;
      vector<int> count_s(26, 0), count_p(26, 0);
      
      for(char c:p) count_p[c-'a']++;
      
      while(h<n) {
        
        count_s[s[h]-'a']++;
        
        if(h-l+1==m) {
          if(validate(count_s, count_p)) {
            out.push_back(l);
          }
          count_s[s[l++]-'a']--;
        }
        
        h++;

      }
      
      return out;
    }
};