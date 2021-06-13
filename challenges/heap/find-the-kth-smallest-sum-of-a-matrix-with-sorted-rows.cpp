// https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
      int m=mat.size(), n=mat[0].size(), sum=0;
      priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> q;
      map<vector<int>, bool> mp;
      
      vector<int> selection(m, 0);
      for(int i=0;i<m;i++) {
        sum+=mat[i][0];
      }
      q.push({sum, selection});
      
      while(k) {
        pair<int, vector<int>> p = q.top();
        q.pop();
        sum=p.first;
        if(mp[p.second]) continue;
        
        for(int i=0;i<m;i++) {
          
          int lsum = p.first;
          vector<int> s = p.second;
          
          if(s[i]+1<n)  {
            s[i]++;
            int val = p.first + (mat[i][s[i]]-mat[i][s[i]-1]);
            q.push({val, s});
          }
        }
        
        mp[p.second] = true;
        k--;
      }
      
      return sum;
    }
};