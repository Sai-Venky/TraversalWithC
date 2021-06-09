// https://leetcode.com/problems/maximum-score-from-removing-stones/

class Solution {
public:
    int maximumScore(int a, int b, int c) {
      priority_queue<int> q;
      q.push(a); q.push(b); q.push(c);
      int out=0;
      
      while(q.size()>1) {
        a = q.top(); q.pop();
        b = q.top(); q.pop();
        out++; a--; b--;
        if(a>0) q.push(a);
        if(b>0) q.push(b);
      }
      return out;
    }
};