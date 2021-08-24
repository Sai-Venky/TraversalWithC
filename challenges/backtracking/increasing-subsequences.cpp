// https://leetcode.com/problems/increasing-subsequences


/*
    Iterative
    class Solution {
        public:
            vector<vector<int>> findSubsequences(vector<int>& a) {
                set<vector<int>> seqs = {vector<int>(0)};
                for (int i = 0; i < a.size(); i++) {
                    vector<vector<int>> built(seqs.size());
                    std::copy(seqs.begin(), seqs.end(), built.begin());
                    for (auto seq : built) {
                        if (seq.empty() || a[i] >= seq.back()) {
                            seq.push_back(a[i]);
                            seqs.insert(seq);
                        }
                    }
                }
                
                vector<vector<int>> res;
                for (auto seq : seqs)
                    if (seq.size() > 1) res.push_back(seq);

                return res;
            }
        };
*/ 

/*
  // Note the use of set here to avoid same level duplicates
    Backtracking
    class Solution {
        public:
            vector<vector<int>> findSubsequences(vector<int>& nums) {
                vector<vector<int>> res;
                vector<int> seq;
                dfs(res, seq, nums, 0);
                return res;
            }
            
            void dfs(vector<vector<int>>& res, vector<int>& seq, vector<int>& nums, int pos) {
                if(seq.size() > 1) res.push_back(seq);
                unordered_set<int> hash;
                for(int i = pos; i < nums.size(); ++i) {
                    if((seq.empty() || nums[i] >= seq.back()) && hash.find(nums[i]) == hash.end()) {
                        seq.push_back(nums[i]);
                        dfs(res, seq, nums, i + 1);
                        seq.pop_back();
                        hash.insert(nums[i]);
                    }
                }
            }
        };
*/

// Unoptimized
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
      unordered_map<int, vector<vector<int>>> m;
      set<vector<int>> s;
      int n=nums.size();
      vector<vector<int>> out;
      
      for(int i=0;i<n;i++) {
        for(int j=0;j<i;j++) {
          if(nums[i]>=nums[j]) {
            if(!s.count({{nums[j], nums[i]}})) {
              m[i].push_back({nums[j], nums[i]});
              s.insert(m[i].back());
            }
            for (int k=0; k<m[j].size(); k++) {
              vector<int> temp = m[j][k];
              temp.push_back(nums[i]);
              if(s.count(temp)) continue;
              m[i].push_back(temp);
              s.insert(m[i].back());
            }
              
          }
        }
      }
      
      for(auto v:m) {
        out.insert(out.end(), v.second.begin(), v.second.end());
      }
      
      return out;
    }
};