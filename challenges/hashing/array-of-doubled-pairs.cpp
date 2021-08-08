// https://leetcode.com/problems/array-of-doubled-pairs

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
      // Note the use of unordered map and sort here. To ensure that elements are seen from start
      unordered_map<int, int> m;
      sort(arr.begin(),arr.end());
      for(int a:arr) {
        m[a]++;
      }
      
      for(int i=0;i<arr.size();i++) {
        if(m.find(2*arr[i]) !=m.end() && m.find(arr[i]) !=m.end()) {
          m[arr[i]]--;
          m[2*arr[i]]--;
          if(m[arr[i]]==0) m.erase(arr[i]);
          if(m[2*arr[i]]==0) m.erase(2*arr[i]);
        }
      }
      
      return m.empty();
    }
};
