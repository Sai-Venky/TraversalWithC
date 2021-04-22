// https://leetcode.com/problems/accounts-merge/

class Solution {
public:
    int parent(int k, vector<int>& count) {
      while(k!=count[k]) {
        k=count[k];
      }
      return k;
    }
  
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
      unordered_map<string, int> umap;
      vector<int> count(accounts.size());
      for(int i=0;i<accounts.size();i++) { 
        auto account = accounts[i];
        count[i] = i;
        for(int j=1;j<account.size();j++) {
          if(umap.find(account[j]) != umap.end()) {
            int root1 = parent(i, count);
            int root2 = parent(umap[account[j]], count);
            count[root1] = root2;
          } else {
            umap[account[j]] = i;     
          }
        }
      }
      unordered_map<int, vector<string>> result;
      for(auto val:umap) {
        int root = parent(val.second, count);
        result[root].push_back(val.first);
      }
      vector<vector<string>> output;
      for(auto val: result) {
        sort( val.second.begin(), val.second.end() );
        vector<string> tmp = { accounts[val.first][0] };
        tmp.insert( tmp.end(), val.second.begin(), val.second.end() );
        output.push_back( tmp );
      }
      return output;
    }
};