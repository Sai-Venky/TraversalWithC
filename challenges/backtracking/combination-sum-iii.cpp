// https://leetcode.com/problems/combination-sum-iii

/*
    Backtracking. SF
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<vector<int>> out;
      vector<int> cur;
      findCombinations(out, 1, 0, k, n, cur);
      return out;
    }
    
    void findCombinations(vector<vector<int>>& out, int s, int sum, int k, int n, vector<int>& cur) {
      if(sum==n && cur.size()==k) {
        out.push_back(cur); return;
      }
      if(s==10 || sum>n || cur.size()>k) return;
      cur.push_back(s);
      findCombinations(out, s+1, sum+s, k, n, cur);
      cur.pop_back();
      findCombinations(out, s+1, sum, k, n, cur);
    }
};