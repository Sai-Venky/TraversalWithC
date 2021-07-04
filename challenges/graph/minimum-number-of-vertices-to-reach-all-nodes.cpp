// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
      map<int, bool> mp;
      for(auto edge:edges) {
        mp[edge[1]]=true;
      }
      
      vector<int> out;
      for(int i=0;i<n;i++) {
        if(!mp[i]) out.push_back(i);
      }
      return out;
      
    }
};