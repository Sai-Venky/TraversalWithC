// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii

class Solution {
public:
    string removeDuplicates(string str, int k) {
      
      stack<pair<char, int>> s;
      
      for(int i=0;i<str.length();i++) {
        
        if(!s.empty() && s.top().first == str[i]) {
          s.top().second++;
        } else {
          s.push({str[i], 1});
        }
        
        if(s.top().second == k) s.pop();
        
      }
      string out="";
      while(!s.empty()) {
        for(int i=0;i<s.top().second;i++) {
          out+=s.top().first;          
        }
        s.pop();
      }
      return string(out.rbegin(), out.rend());
    }
};