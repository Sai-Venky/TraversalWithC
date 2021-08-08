// https://leetcode.com/problems/top-k-frequent-words/

/*
  Code  - SF. Note use of pair op to track freq
  Logic - Heap
*/

class Solution {
public:
    struct Frequency {
      bool operator()(const pair<string, int> &p1, const pair<string, int> &p2) {
        if(p1.second == p2.second) return p1.first>p2.first;
        return p1.second < p2.second;
      }
    };
    priority_queue<pair<string, int>, vector<pair<string, int>>, Frequency> q;
  
    vector<string> topKFrequent(vector<string>& words, int k) {
      vector<string> out;
      map<string, int> mp;
      for(auto str:words) mp[str]++;
      
      for(auto val:mp)  {
        q.push({val.first, val.second});
      }
      
      while(!q.empty() && k>0) {
        pair<string, int> p = q.top();
        q.pop();
        out.push_back(p.first);
        k--;
      }
      return out;
    }
};