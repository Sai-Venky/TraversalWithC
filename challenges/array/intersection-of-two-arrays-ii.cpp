// https://leetcode.com/problems/intersection-of-two-arrays-ii/

// SF 

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count;
        vector<int> inter;
      
      for(auto num:nums1) { count[num]++;}
      for(auto num:nums2) { 
        if(count[num]) {
          inter.push_back(num);
          count[num]--;
        }
      }
      return inter;
    }
};