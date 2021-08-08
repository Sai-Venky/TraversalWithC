// https://leetcode.com/problems/subsets-ii/

/*  
  Logic - Backtracking
  Code  - SF
*/

class Solution {
public:
    vector<vector<int>> outputs;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<int> output;
      sort(nums.begin(), nums.end());
      findSubsets(nums, 0, output);
      return outputs;
    }
  
    void findSubsets(vector<int>& nums, int start, vector<int>& output) {
      outputs.push_back(output);

      for(int i=start;i<nums.size();i++) {
        if(i > start && nums[i] == nums[i-1]) continue; 
        output.push_back(nums[i]);
        findSubsets(nums, i+1, output);
        output.pop_back();
      }
    }
};