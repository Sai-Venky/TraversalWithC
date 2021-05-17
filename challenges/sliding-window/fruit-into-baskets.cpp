// https://leetcode.com/problems/fruit-into-baskets

class Solution {
public:
    int totalFruit(vector<int>& tree) {
      
      int ct=0, l=0, h=0, n=tree.size();
      unordered_map<int, int> m;
      for(h=0;h<n;h++) {
        m[tree[h]]++;
        
        while(m.size() > 2) {
          m[tree[l]]--;
          if(m[tree[l]] == 0) m.erase(tree[l]);
          l++;
        }
        ct=max(ct, h-l+1);
      }
      
      return ct;
    }
};