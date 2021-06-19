// https://leetcode.com/problems/destination-city

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> count;
        for(auto path:paths) {
          count[path[0]]--; 
          count[path[1]]++; 
        }
        for(auto val:count) {
          if(val.second>0) return val.first;
        }
      return "";
    }
};