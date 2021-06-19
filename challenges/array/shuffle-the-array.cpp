// https://leetcode.com/problems/shuffle-the-array/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>output;
        
        for(int i = 0; i < n; i++){
            
            output.push_back(nums[i]);
            output.push_back(nums[i+n]);
        }
     return output;  
    }
};