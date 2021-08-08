// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings

// https://federico-feresini.medium.com/split-a-string-into-the-max-number-of-unique-substrings-algorithms-visualizations-6116561b7fc6
// Bit based approach

/*  
  Logic - Backtracking
  Code  - SF
*/

class Solution {
public:
    unordered_set<string> s;
    int out=0;
    int maxUniqueSplit(string str) {
      split(str, 0);
      return out;
    }
  
    void split(string str, int start) {
      
      if(start==str.length()) {
        if(s.size()>out) out=s.size();
        return;
      }
      string comb="";
      for(int i=start;i<str.length();i++) {
        comb.push_back(str[i]);
        if(s.count(comb)>0) continue;
        s.insert(comb);
        split(str, i+1);
        s.erase(comb);
      }
      
    }
};