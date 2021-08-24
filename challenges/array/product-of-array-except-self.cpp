// https://leetcode.com/problems/product-of-array-except-self

// Note the way of traversing twice one in front and other back. 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int> output(nums.size(), 1);
      int start=1, end=1;
      
      for(int i=0;i<nums.size();i++) {
        output[i]*=start;
        start*=nums[i];
      }
      
      for(int i=nums.size()-1;i>=0;i--) {
        output[i]*=end;
        end*=nums[i];
      }
      
      return output;
    }
};