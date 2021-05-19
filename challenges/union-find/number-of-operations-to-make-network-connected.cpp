// https://leetcode.com/problems/number-of-operations-to-make-network-connected/


/*
    Important to note that To connect all nodes need at least n-1 edges
*/

/*

    BFS 
    class Solution {
public:
    void bfs(int i,vector<int>&visited,vector<vector<int>>&mat)
    {
        visited[i]=1;
        queue<int>q;
        q.push(i);
        while(!q.empty())
        {
            int k = q.front();
            q.pop();
            for(auto c: mat[k])
            {
                if(!visited[c])
                {
                    visited[c]=1;
                    q.push(c);
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1; //if number of connections are less than required number of edges to make the graph connected, then simply return -1 as it is not possible.
        vector<vector<int>>mat(n); 
        for(auto c: connections)
        {
        mat[c[0]].push_back(c[1]);
        mat[c[1]].push_back(c[0]);
        }
        vector<int>visited(n,0);
        int count = 0;
        for(int i=0;i<n;i++)
        {
          if(visited[i]==0)
          {
              count++;
              bfs(i,visited,mat);
          }
        }
        return count-1; //if there are n components then n-1 wires are needed to make it connected.
    }
};
*/
class Solution {
public:
  vector<int>parent;
    int find(int x) {
        return parent[x] == x ? x : find(parent[x]);
    }
  
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int m = connections.size();
        
        if (n-1 > m) return -1;

        parent.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        for (int i = 0; i < m; i++) {
              int x = find(connections[i][0]);
              int y = find(connections[i][1]);
              if (x != y) {
                parent[y] = x;
              }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (parent[i] == i)
                ans++;
        
        return ans-1;
        
    }
};
