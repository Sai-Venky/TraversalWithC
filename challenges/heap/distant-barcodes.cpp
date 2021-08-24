// https://leetcode.com/problems/distant-barcodes

/*
  Code  - SF. Note use of map to count frequency
  Logic - Heap
  T-O(nlogn)
  S-O(n)
*/

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
      priority_queue<pair<int, int>> q;
      unordered_map<int, int> m;
      vector<int> output;
      for(int barcode:barcodes) m[barcode]++;
      
      for(auto val:m) q.push({val.second, val.first});
      
      while(q.size() > 1) {
        pair<int, int> p1 = q.top(); q.pop();
        pair<int, int> p2 = q.top(); q.pop();
        output.push_back(p1.second);
        output.push_back(p2.second);
        if(p1.first-1 > 0) q.push({p1.first-1, p1.second});
        if(p2.first-1 > 0) q.push({p2.first-1, p2.second});
      }
      
      if(!q.empty()) {
        output.push_back(q.top().second);
      }
      return output;
    }
};