// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:

    struct Frequency {
      bool operator()(const pair<char, int> &p1, const pair<char, int> &p2) {
        return p1.second < p2.second;
      }
    };
    priority_queue<pair<char, int>, vector<pair<char, int>>, Frequency> q;
  
    string frequencySort(string s) {
      string out="";
      map<char, int> mp;
      for(auto c:s) mp[c]++;
      
      for(auto val:mp)  {
        q.push({val.first, val.second});
      }
      
      while(!q.empty()) {
        pair<char, int> p = q.top();
        q.pop();
        while(p.second>0) {
          out+=p.first;
          p.second--;
        }
      }
      return out;
    }
};