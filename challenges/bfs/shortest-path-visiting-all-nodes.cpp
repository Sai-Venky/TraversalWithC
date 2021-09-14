// https://leetcode.com/problems/shortest-path-visiting-all-nodes

/*
    Note the use of bit mask here.
    Note the use of visited tracking here.
    https://leetcode.com/problems/shortest-path-visiting-all-nodes/discuss/504660/Thinking-Process%3A-BFS
    https://leetcode.com/problems/shortest-path-visiting-all-nodes/discuss/277082/Java-BFS-solution-beats-98.98-with-explanation
    https://leetcode.com/problems/shortest-path-visiting-all-nodes/discuss/152679/Short-Java-Solution-BFS-with-a-Set
    Read other solutions
*/

class Solution {
public:
    struct Node {
      int val;
      int mask;
      
      Node(int v, int m) {
        val=v;
        mask=m;
      }
    };
  
    int shortestPathLength(vector<vector<int>>& graph) {
      
      int out=0, ans=(1<<graph.size())-1;
      queue<Node> q;
      vector<vector<bool>> vis(graph.size(), vector<bool>(ans+1, false));
      for(int i=0;i<graph.size();i++) {
        q.push(Node(i, 1<<i));
      }
      
      while(!q.empty()) {
        int nn=q.size();
        
        for(int i=0;i<nn;i++) {
          
          Node n=q.front(); q.pop();
          
          if(n.mask==ans) return out; 
          if(vis[n.val][n.mask]==true) continue;
          vis[n.val][n.mask] = true;
          int mask=n.mask, val=n.val;
          for(int val:graph[n.val]) {
            n.val=val;
            n.mask=(1<<val)|mask;
            q.push(n);
          }
        }
        out++;
      }
       
      return -1;
    }
};