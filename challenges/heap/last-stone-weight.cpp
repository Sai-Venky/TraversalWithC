// https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      priority_queue<int> q;  
      for(auto stone:stones) q.push(stone);
      
      while(!q.empty() && q.size()>=2) {
        int first=q.top(); q.pop();
        int sec=q.top(); q.pop();
        if(first!=sec) q.push(first-sec);
      }
      
      return q.size()==0?0:q.top();
    }
};