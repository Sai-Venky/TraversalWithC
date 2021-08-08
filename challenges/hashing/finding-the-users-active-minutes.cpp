// https://leetcode.com/problems/finding-the-users-active-minutes

// SF
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
      vector<int> uam(k, 0);
      map<int, set<int>> m;
      
      for(auto log:logs) {
        m[log[0]].insert(log[1]);
      }
      
      for(auto v:m) {
        uam[v.second.size()-1]++;
      }
      
      return uam;
    }
};