// https://leetcode.com/problems/sum-of-even-numbers-after-queries/

// SF

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
      vector<int> out;
      int sum=0;
      for(int num:nums) {
        sum=num%2==0?sum+num:sum;
      }
      for(vector<int> query:queries) {
        int prev=nums[query[1]];
        if(nums[query[1]] % 2==0) sum-=nums[query[1]];
        nums[query[1]] += query[0]; 
        if(nums[query[1]] % 2==0) sum+=nums[query[1]];
        out.push_back(sum);
      }
      
      return out;
    }
};