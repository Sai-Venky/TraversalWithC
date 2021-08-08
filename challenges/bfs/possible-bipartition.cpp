// https://leetcode.com/problems/possible-bipartition/


/*  
  Logic - BFS. Note use of vector to convert to graph
  Code  - Note the use of color to depict dislike in BFS.
*/


class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
      
      vector<int> color(N, 0);
      
      vector<vector<int>> v(N, vector<int>());
      
      for(auto d:dislikes) {
        v[d[0]-1].push_back(d[1]-1); 
        v[d[1]-1].push_back(d[0]-1); 
      }
      
      
      for(int i=0; i<N; i++) {
        if(color[i] != 0){
          continue;
        }
        queue<int> q;
        
        q.push(i);
        color[i] = 1;
        while(!q.empty()) {
          int l = q.front();
          vector<int> dislike = v[l];
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