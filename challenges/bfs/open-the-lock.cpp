// https://leetcode.com/problems/open-the-lock/

/*

    Note that For each position the wheel can move on step up or down.
    So try doing that to all 4 positions in start 0000. Those all would become next state. 
    Check when its equal to target and return. Keep visited to ensure duplicates dont come.

*/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
      
      unordered_map<string, bool> visited;
      
      for(auto deadend:deadends) visited[deadend]=true;
      queue<string> q;
      q.push("0000");
      int ct=0;
      while(!q.empty()) {
        int n=q.size();
        
        for(int i=0;i<n;i++) {
          string s=q.front(); q.pop();
          
          if(s == target) return ct;
          if(visited[s]) continue;
          visited[s] = true;
          for(int j=0;j<4;j++) {
            string t = s;
            int n1 = t[j] - '0' + 1;
            int n2 = t[j] - '0' - 1;
            
            n2 = n2<0?n2+10:n2;
            n1 = n1%10; n2 = n2%10;
            
            t[j] = n1 + '0'; q.push(t);
            
            t[j] = n2 + '0'; q.push(t);
          }
        }
        ct++;

      }
      
      
      return -1;
    }
};