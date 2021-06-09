// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    struct Frequency {
      bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.first < p2.first;
      }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
      priority_queue<pair<int, int>, vector<pair<int, int>>, Frequency> q;
      
      map<int, int> mp;
      for(int num:nums) mp[num]++;
      
      for(auto val:mp)  {
        q.push({val.second, val.first});
      }
      
      vector<int> output;
      while(k>0) {
        pair<int, int> p = q.top();
        q.pop();
        output.push_back(p.second);
        k--;
      }
      
      return output;
    }
};