// https://leetcode.com/problems/arithmetic-subarrays

// SF

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
      vector<bool> output;
      for(int i=0;i<l.size();i++) {
        int left = l[i], right = r[i];
        vector<int> v;
        
        for(int j=left; j<=right; j++) {
          v.push_back(nums[j]);
        }
        
        sort(v.begin(), v.end());
        if(v.size() == 1) output.push_back(true);
        int diff = v[1] - v[0];
        bool valid = true;
        for (int j=2; j<v.size(); j++) {
          if(v[j] - v[j-1] != diff) {
            valid = false;
            break;
          }
        }
        if(valid) {
          output.push_back(true);  
        } else {
          output.push_back(false);
        }

      }
      return output;
    }
};