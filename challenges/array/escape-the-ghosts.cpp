// https://leetcode.com/problems/escape-the-ghosts

/*
    Note the use of manhatten distance and logic here.
    The best place for the ghost is to go to target directly and wait there for player.
*/

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& t) {
      int d = abs(t[0]) + abs(t[1]);
      for(auto g: ghosts)
          if (d >= abs(t[0] - g[0]) + abs(t[1] - g[1]))
              return false;
      return true;
    }
};