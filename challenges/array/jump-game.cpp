// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {        
        if(nums.size() == 1) return true;
        int countTillNow = nums[0];

        for(int i=1; i<nums.size(); i++) {
            countTillNow--;
            if(countTillNow <0) {
                break;
            }
            if(nums[i] > countTillNow) {
                countTillNow = nums[i];
            }

        }
        
        return countTillNow<0?false:true;
    }
};