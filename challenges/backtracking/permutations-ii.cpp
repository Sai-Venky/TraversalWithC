// https://leetcode.com/problems/permutations-ii

/*  
  Logic - Backtracking
  Code  - Checking the use of count to check total count is valid
*/

class Solution {
public:
    vector<vector<int>> outputs;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<int> output;
      sort(nums.begin(), nums.end());
      findPermutations(nums, output);
      return outputs;        
    }
  
    void findPermutations(vector<int>& nums, vector<int>& output) {
      if(output.size()==nums.size()) {
        outputs.push_back(output);
        return;
      }

      for(int i=0;i<nums.size();i++) {
        if(i>0 && nums[i] == nums[i-1]) continue; 
        if(count(output.begin(), output.end(), nums[i]) == count(nums.begin(), nums.end(), nums[i])) continue; 
        output.push_back(nums[i]);
        findPermutations(nums, output);
        output.pop_back();
      }
    }
};