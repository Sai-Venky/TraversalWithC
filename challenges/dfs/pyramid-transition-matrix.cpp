// https://leetcode.com/problems/pyramid-transition-matrix

/*  
  IMP
  Logic - DFS
  Code  - next string is reused
*/
class Solution {
public:
  bool pyramidTransition(string bottom, vector<string>& allowed) {
    unordered_map<string, vector<char>> m;
    for(auto& s:allowed) m[s.substr(0, 2)].push_back(s.back());
    return helper(bottom, m, 0, "");
  }
  bool helper(string bottom, unordered_map<string, vector<char>>& m, int start, string next){
    if(bottom.size() == 1) return true;
    if(start == (int)bottom.size() - 1) return helper(next, m, 0, "");
    for(char c : m[bottom.substr(start, 2)])
      if(helper(bottom, m, start+1, next+c)) return true;
    return false;
  }
};