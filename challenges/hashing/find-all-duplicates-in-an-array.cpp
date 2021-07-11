// https://leetcode.com/problems/find-all-duplicates-in-an-array

/*
    class Solution {
        public:
            vector<int> findDuplicates(vector<int>& nums) {
                vector<int> res;
                int i = 0;
                while (i < nums.size()) {
                    if (nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
                    else i++;
                }
                for (i = 0; i < nums.size(); i++) {
                    if (nums[i] != i + 1) res.push_back(nums[i]);
                }
                return res;
            }
        };
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
      int n=nums.size();
      vector<int> res;
      for(int i=0;i<n;i++) {
        nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        if(nums[abs(nums[i])-1] > 0) res.push_back(abs(nums[i]));
      }
      return res;
    }
};