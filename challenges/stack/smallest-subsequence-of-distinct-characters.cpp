// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters

/*
  Logic - SF. same as remove duplicate characters
  Code - Stack
 */

class Solution {
public:
    string smallestSubsequence(string str) {
      
      map<char, int> m;
      map<char, bool> vis;
      string out;
      for(auto c:str) m[c]++;

      
      for(int i=0;i<str.size();i++) {
      
        m[str[i]]--;
        if(vis[str[i]]) continue;
        
        while(!out.empty() && m[out.back()]>0 && out.back() > str[i]) {
          vis[out.back()] = false;
          out.pop_back();
        }
        out.push_back(str[i]);
        vis[str[i]] = true;
      }
      
      return out;
    }
};