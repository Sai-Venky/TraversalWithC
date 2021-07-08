// https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree

class Solution {
public:
    int find(vector<int> &parent, int x) {
      if(parent[x]==-1) return x;
      parent[x]=find(parent, parent[x]);
      return parent[x];
    }
  
    int mst(vector<vector<int>>& edges, int n, int skip, int preedge=-1) {
      int mstdist=0, e=0;
      vector<int> parent(n, -1);
      if(preedge!=-1) {
        int u=find(parent,edges[preedge][2]);
        int v=find(parent,edges[preedge][1]);
        if(u != v) 
        parent[v]=u; 
        mstdist+=edges[preedge][0];
        e++;
      }
      for(int i=0;i<edges.size();i++) {
        if(skip==i) continue;
        int u=find(parent,edges[i][2]);
        int v=find(parent,edges[i][1]);
        if(u==v) continue;
        parent[v]=u; 
        mstdist+=edges[i][0];
        e++;
        if(e==n-1) break;
      }
      if (skip!=-1 && e<n-1) return INT_MAX;

      return mstdist;
    }
  
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
      vector<vector<int>> out(2);      
      for(int i=0;i<edges.size();i++) {
        edges[i].push_back(i);
      }
      for(int i=0;i<edges.size();i++) {
        int tmp=edges[i][0];
        edges[i][0]=edges[i][2];
        edges[i][2]=tmp;
      }
      sort(edges.begin(),edges.end());
      int mstdist = mst(edges, n, -1);
      for(int i=0;i<edges.size();i++) {
        if(mst(edges, n, i) > mstdist) {
          out[0].push_back(edges[i][3]);
        } else if(mst(edges, n, -1, i) == mstdist){
          out[1].push_back(edges[i][3]);          
        }
      }
      return out;
    }
};