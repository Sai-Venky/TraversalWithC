// https://leetcode.com/problems/move-zeroes

//Sf 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0, i = 0;
        for (; i < nums.size(); i ++)  {
            if (nums[i] !=0) {
                nums[j++] = nums[i];
            }
        }
        for (; j < nums.size();)  {
            nums[j++] = 0;
        }
    }
};