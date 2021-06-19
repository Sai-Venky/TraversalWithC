// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph)  {
      int N =graph.size();
      vector<int> color(N, 0);
      
      for(int i=0; i<N; i++) {
        if(color[i] != 0){
          continue;
        }
        queue<int> q;
        
        q.push(i);
        color[i] = 1;
        while(!q.empty()) {
          int l = q.front();
          vector<int> dislike = graph[l];
          q.pop();
          for(auto val: dislike) {
            
            if(color[val] == 0) {
              color[val] = -1 *color[l];
              q.push(val);
            } else if(color[val] == color[l]) {
              return false;
            }
          }

        }
        
      }
      
      return true;
    }
};