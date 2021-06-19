// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int track = 1, end = 1;
            
        while(end<nums.size()) {
            
            if(nums[end] != nums[end-1]) {
                nums[track++] = nums[end];
            }
            end++;
        }
        
        return track;
        
    }
};