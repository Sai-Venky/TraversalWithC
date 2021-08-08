// https://leetcode.com/problems/all-paths-from-source-to-target

/*  
  Logic - Backtracking
  Code  - SF
*/

class Solution {
    vector<vector<int>> outputs;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      int n = graph.size();
      vector<int> output;
      output.push_back(0);
      dfs(graph, output, 0);
      return outputs;
    }
  
    void dfs(vector<vector<int>>& graph, vector<int>& output, int pos) {
      if(pos==graph.size()-1) {
        outputs.push_back(output);
        return;
      }
      vector<int> neighbours = graph[pos];
      for(int i=0;i<neighbours.size();i++) {
        output.push_back(neighbours[i]);
        dfs(graph, output, neighbours[i]); 
        output.pop_back();
      }
    }
};