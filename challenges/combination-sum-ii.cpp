// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
    vector<vector<int>> outputs;
    int targetSum;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      targetSum=target;
      vector<int> output;
      sort(candidates.begin(), candidates.end());
      findcombinationSum(candidates, output, 0, 0);
      return outputs;
    }
  
    
    void findcombinationSum(vector<int>& nums, vector<int>& output, int sum, int start) {
      if(sum==targetSum) {
        outputs.push_back(output);
        return;
      } else if(sum>targetSum) {
        return;
      }

      for(int i=start;i<nums.size();i++) {
        if(i>start && nums[i] == nums[i-1]) continue; 
        output.push_back(nums[i]);
        findcombinationSum(nums, output, sum+nums[i], i+1);
        output.pop_back();
      }
    }
};