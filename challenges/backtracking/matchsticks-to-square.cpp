// https://leetcode.com/problems/matchsticks-to-square/

/*  
  Logic - Backtracking
  Code  - SF
*/

class Solution {
public:
    bool dfs(vector<int>& nums, vector<int>& sums, int index, int *target) {
    	if (index == nums.size()) {
    	    if (sums[0] == *target && sums[1] == *target && sums[2] == *target) {
    		    return true;
    	    }
    	    return false;
    	}
    	
    	for (int i = 0; i < 4; i++) {
    	    if (sums[i] + nums[index] > *target) continue;
    	    sums[i] += nums[index];
            if (dfs(nums, sums, index + 1, target)) return true;
    	    sums[i] -= nums[index];
    	}
    	
    	return false;
    }
  
    bool makesquare(vector<int>& matchsticks) {
      int sum=0, l;
      vector<int> sums(4, 0);
      for(auto matchstick:matchsticks) sum+=matchstick;
      if(sum%4!=0) return false;
      l=sum/4;
      
      sort(matchsticks.begin(), matchsticks.end());
      reverse(matchsticks.begin(), matchsticks.end());
      return dfs(matchsticks, sums, 0, &l);
    }
};