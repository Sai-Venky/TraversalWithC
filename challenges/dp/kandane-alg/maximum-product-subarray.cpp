// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int curMax = nums[0];
        int curMin = nums[0];
        int ans = curMax;
        
        for (int i = 1; i < n; i++) {
            int tmp = curMax;
            curMax = max(tmp*nums[i], max(curMin*nums[i], nums[i]));
            curMin = min(tmp*nums[i], min(curMin*nums[i], nums[i]));
            
            ans = max(ans, curMax);
        }

        return ans;
    }
};