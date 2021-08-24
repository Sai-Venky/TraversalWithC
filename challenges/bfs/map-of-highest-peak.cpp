// https://leetcode.com/problems/map-of-highest-peak

// SF BFS

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    
      int m=isWater.size(),n=isWater[0].size();
      queue<pair<int,int>> q;
      for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
          if(isWater[i][j]) {
            isWater[i][j] = 0;
            q.push(make_pair(i,j));
          } else {
            isWater[i][j] = -1;
          }
        }
      }
      
      vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
      int l=1;
      while(!q.empty()) {
        int size=q.size();
        
        for(int k=0;k<size;k++) {
          
          pair<int,int> p = q.front();
          
          for(auto dir:dirs) {
            int i = dir[0] + p.first;
            int j = dir[1] + p.second;
            if(i>=0 && i<m && j>=0 && j<n && isWater[i][j]==-1) {
              isWater[i][j] = l;
              q.push(make_pair(i, j));
            }
          }
          
          q.pop();
          
        }
        l++;
        
      }
      return isWater;
    
    }
};