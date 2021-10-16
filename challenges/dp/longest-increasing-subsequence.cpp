// https://leetcode.com/problems/longest-increasing-subsequence

// https://leetcode.com/problems/longest-increasing-subsequence/discuss/152065/Python-explain-the-O(nlogn)-solution-step-by-step

/*
Given this example [8, 2, 5, 1, 6, 7, 9, 3]
And the resultant array sub = [1, 3, 6, 7, 9]

Let's look at the each of the values in sub and use the given input array to see the possible subsequences for each size.
At index 0, 1 is the smallest tail that can give us a subsequence of size 1
At index 1, 3 is the smallest tail that can give us a subsequence of size 2, [1,3] or [2,3]
At index 2, 6 is the smallest tail that can give us a subsequence of size 3, [2,5,6]
At index 3, 7 is the smallest tail that can give us a subsequence of size 4, [2,5,6,7]
At index 4, 9 is the smallest tail that can give us a subsequence of size 5, [2,5,6,7,9]

For index 0, we can basically pick any element. But, 1 is the smallest value possible. By ordering the elements in sub in ascending order we are trying to ensure that the largest number in the subsequence ending at each position (i.e. the tail) is as small as possible. This means that we can maximize the probability of being able to pick subsequent subsequences of length 4, 5 etc.
When we select 9 for a subsequence of length 1, we can no longer pick any other increasing numbers that result in an increasing subsequence.

As another example, for subsequence of size 3, the possible subsequences are [2,5,6] [2,6,7] [2,7,9] [5,6,7] [1,6,7] [6,7,9]. Our algorithm ended up picking [2,5,6] by placing the 6 at that position.

Corrections or suggestions are welcome.

class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums == null || nums.length ==0){
            return 0;
        }
        int[] dp = new int[nums.length];
        int max = 0;
        for(int i=0; i<nums.length; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i]>nums[j]) {
                    dp[i] = Math.max(dp[i], dp[j]+1);
                    max = Math.max(max, dp[i]);
                }
            }
        }
        return  max+1;
    }
}
*/

class Solution {
public:
    int bs(vector<int>& dp, int l, int h, int num) {
      int m=0;
      while(l<=h){
        m = l + (h-l)/2;  
        if(dp[m] == num) {
            return m;
        } else if(dp[m] >= num) {
          h=m-1;
        } else {
          l=m+1;
        }
      }
      return l;
      
    }
  
    int lengthOfLIS(vector<int>& nums) {
      
      int n=nums.size();
      vector<int> dp(n);
      dp[0] = nums[0];
      int size=0;
      
      for(int i=0;i<n;i++) {

        if(nums[i] > dp[size]) {
            dp[++size] = nums[i];
        }
        else {
          int p = bs(dp, 0, size, nums[i]);
          dp[p] = nums[i];
        }

      }
      return size+1;
      
    }
};