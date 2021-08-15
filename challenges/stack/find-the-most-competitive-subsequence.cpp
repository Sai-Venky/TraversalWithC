// https://leetcode.com/problems/find-the-most-competitive-subsequence

/*
  Logic - Note the use of stack. Good Question
  https://leetcode.com/problems/find-the-most-competitive-subsequence/discuss/952786/JavaC%2B%2BPython-One-Pass-Stack-Solution
  Code- Stack
*/

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& A, int k) {
        vector<int> stack;

        for (int i = 0; i < A.size(); ++i) {
            while (!stack.empty() && stack.back() > A[i] && stack.size()+A.size()-i>k)
                stack.pop_back();
            if (stack.size() < k)
                stack.push_back(A[i]);
        }
        return stack;
    }
};

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
      
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
      
      int i=0, prev=0;
      
      for(i=0;i<nums.size()-k+1;i++) {
        q.push({nums[i], i});
      }
      vector<int> out;
      while(k) {
        pair<int, int> p = q.top();
        q.pop();
        if(p.second < prev) continue;
        out.push_back(p.first);
        prev = p.second;
        if(i<nums.size()) {
          q.push({nums[i], i}); i++;
        }
        k--;
        
      }
      return out;
    }
};