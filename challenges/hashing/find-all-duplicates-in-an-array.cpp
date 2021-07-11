// https://leetcode.com/problems/find-all-duplicates-in-an-array

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
      int n=nums.size();
      vector<int> res;
      for(int i=0;i<n;i++) {
        nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        if(nums[abs(nums[i])-1] > 0) res.push_back(abs(nums[i]));
      }
      return res;
    }
};