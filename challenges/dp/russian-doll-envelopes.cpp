// https://leetcode.com/problems/russian-doll-envelopes


/*
class Solution {
public:
    static bool compare(vector<int>&a , vector<int>& b)
    {
      return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>&a) {
      sort(a.begin(),a.end(),compare);
      vector<int>dp;
      for(auto i:a)
      {
        auto it=lower_bound(dp.begin(),dp.end(),i[1]);
        if(it==dp.end())
          dp.push_back(i[1]);
        else
          *it=i[1];
        cout<<dp.size()<<" ";
      }
      return dp.size();
    }
};
*/
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& es) {
      sort(es.begin(), es.end());
      int n=es.size();
      vector<int> dp(n, 1);
      int ct=0;
      
      for(int i=0;i<n;i++) {
        
        int l=0;
        while(l<i) {
          
          if(es[i][0]>es[l][0] && es[i][1]>es[l][1]) {
            dp[i] = max(dp[i], dp[l]+1);
          }
          l++;
        }
        ct=max(ct, dp[i]);
      }
      
      return ct;
    }
};