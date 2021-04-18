// https://leetcode.com/problems/largest-number

class Solution {
public:
    string largestNumber(vector<int>& nums) {
      string out = "";
      for(int i=0; i<nums.size(); i++) {
        for(int j=0; j<nums.size(); j++) {
          string no1 = to_string(nums[i]);
          string no2 = to_string(nums[j]);
          if((no1+no2) > (no2+no1)) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
          }
        }
      }
      
      for(auto num:nums) {
        out+=to_string(num);
      }
      return out[0] == '0' ? "0":out;
    }
};