// https://leetcode.com/problems/remove-duplicate-letters/

/*
  Logic - SF. Note the use of logic of monotonic stack here. Ignoreing duplicates when smalled element exist later on.
  Code - Stack
 */

class Solution {
public:
    string removeDuplicateLetters(string str) {
      
      map<char, int> m;
      map<char, bool> vis;
      stack<char> s;
      string out;
      for(auto c:str) m[c]++;

      
      for(int i=0;i<str.size();i++) {
      
        m[str[i]]--;
        if(vis[str[i]]) continue;
        
        while(!s.empty() && m[s.top()]>0 && s.top() > str[i]) {
          out.pop_back();
          vis[s.top()] = false;
          s.pop();
        }
        s.push(str[i]);
        out.push_back(str[i]);
        vis[str[i]] = true;
      }
      
      return out;
    }
};