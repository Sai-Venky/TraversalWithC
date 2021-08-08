// https://leetcode.com/problems/furthest-building-you-can-reach

/*
  Code  - SF
  Logic - Heap
*/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
      
      priority_queue<int> q;
            
      int i=1;
      for(i=1;i<heights.size();i++) {
        int need = heights[i]-heights[i-1];
        if(need>0) {
          q.push(need);
          if(bricks < need) {
            if(ladders==0) {
              return i-1;
            }
            bricks+=q.top();
            q.pop();
            ladders--;
          }
          bricks-=need;
        }
        
      }
      
      return i-1;
      
    }
};