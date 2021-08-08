// https://leetcode.com/problems/permutations

/*  
  Logic - Backtracking
  Code  - SF
*/

class Solution {
public:
    vector<vector<int>> outputs;
    vector<vector<int>> permute(vector<int>& nums) {
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
        if(count(output.begin(), output.end(), nums[i])) continue; 
        output.push_back(nums[i]);
        findPermutations(nums, output);
        output.pop_back();
      }
    }
};