// https://leetcode.com/problems/single-threaded-cpu

/*

    Lots of edge cases : -like this [[7,1],[6,3],[1,3]]
    after 1 , its idle so we need to handle that case.
*/

class Solution {
  
  struct minTime {
      bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
        if(p1.second == p2.second) return p1.first > p2.first;
        return p1.second > p2.second;
      }
    };
  
public:

    vector<int> getOrder(vector<vector<int>>& tasks) {
      
      for (int i = 0; i < tasks.size(); ++i) tasks[i].push_back(i);
      sort(tasks.begin(), tasks.end());
      priority_queue<pair<int, int>, vector<pair<int, int>>, minTime > q;
      
      long time = tasks[0][1], elap=tasks[0][0] + time, k=1;
      vector<int> output = {tasks[0][2]};
      
      while(output.size() < tasks.size()) {
        
        while(k<tasks.size() && tasks[k][0] <=elap) {
          q.push({tasks[k][2], tasks[k][1]});
          k++;
        }

        if(!q.empty()) {
          pair<int, int> p = q.top();
          time = p.second;
          output.push_back(p.first);
          q.pop();
        } else if (elap<tasks[k][0]){
          elap = tasks[k][0];
          continue;
        }
        
        elap+=time;
      }
      
      
      return output;
      
    }
};