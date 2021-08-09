// https://leetcode.com/problems/swim-in-rising-water/

// Note the use of no special count variable here for time but instead using the navigation alone to fetch the values in 4 corners and based on that proceeding.
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
      
      priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
      int x=grid.size(), y=grid[0].size();
      vector<vector<bool>> visited(x, vector<bool>(y, false));
      
      q.push({grid[0][0], {0, 0}});
      int mini=grid[0][0];
      
      while(!q.empty()) {
        pair<int, pair<int, int>> p = q.top();
        q.pop();
        int i=p.second.first, j=p.second.second;
        mini=max(mini, p.first);        
        if(i==x-1 && j==y-1) break;
        
        if(i+1<x && !visited[i+1][j]) {
          q.push({grid[i+1][j], {i+1, j}});          
        }
        if(i-1>=0 && !visited[i-1][j]) {
          q.push({grid[i-1][j], {i-1, j}});          
        }
        if(j+1<y && !visited[i][j+1]) {
          q.push({grid[i][j+1], {i, j+1}});          
        } 
        if(j-1>=0 && !visited[i][j-1]) {
          q.push({grid[i][j-1], {i, j-1}});          
        } 
        
        visited[i][j]=true;
      }
      
      return mini;
    }
};