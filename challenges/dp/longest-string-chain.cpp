// https://leetcode.com/problems/longest-string-chain

class Solution {
public:
    static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }
    int longestStrChain(vector<string>& es)  {
      sort(es.begin(), es.end(), compare);
      int n=es.size(), ct=0;
      unordered_map<string, int> dp;
      for(auto word:es) dp[word] = 1;
      
      for(int i=0;i<n;i++) {
        
        int l=0;
        while(l<es[i].length()) {
          string split=es[i].substr(0, l) + es[i].substr(l+1); 
          // cout<<split<<" ";
          if(dp.find(split) != dp.end()) {
            dp[es[i]] = max(dp[es[i]], dp[split]+1);
          } 
          l++;
        }
        ct=max(ct, dp[es[i]]);
        // cout<<dp[es[i]]<<" \n";
      }
      
      return ct;
    }
};