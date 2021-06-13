// https://leetcode.com/problems/ipo

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
      
      priority_queue<int> q;
      int profit=0, n=profits.size();
      set<pair<int,int>> s;
      for(int i=0; i<capital.size();i++) s.insert({capital[i], i});
      set<pair<int,int>>::iterator itr=s.begin();
      
      while(k) {
        
        while(itr!=s.end()) {
          pair<int, int> p = *itr;
          if(p.first > w) break;
          q.push(profits[p.second]);
          itr++;
        }
        
        if(!q.empty()) {
          w+=q.top();q.pop();
        }
        
        k--;
      }
      
      return w;
      
    }
};