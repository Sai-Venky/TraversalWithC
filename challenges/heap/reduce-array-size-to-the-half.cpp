// https://leetcode.com/problems/reduce-array-size-to-the-half/

/*
int minSetSize(vector<int>& arr) {
    unordered_map<int, int> m;
    priority_queue<int> pq;
    for (auto n : arr) ++m[n];
    for (auto &p : m) pq.push(p.second);
    int res = 0, cnt = 0;
    while (cnt * 2 < arr.size()) {
        ++res;
        cnt += pq.top(); pq.pop();
    }
    return res;
}
*/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
      unordered_map<int, int> m;
      map<int, int> v;
      int setsz=0, sz=0;
      for(int e:arr) m[e]++;
      for(auto e:m) v[e.second]++;
      
      for (auto it = v.rbegin(); sz<arr.size()/2 && it != v.rend(); it++) {
        while(it->second>0) {
          if(sz>=arr.size()/2) break;
          sz+=it->first;
          setsz+=1;
          it->second--;
        }
        
      }
      return setsz;
    }
};