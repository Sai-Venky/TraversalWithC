// https://leetcode.com/problems/intersection-of-two-arrays/ 

// SF . Note the use of map to increase and then decrease the count. Finally the greater elements are returned

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      
      map<int,int> m;
      vector<int> output;
      for(auto num:nums1) {
        m[num]++;
      }
      
      for(auto num:nums2) {
        if(m[num]>0)
          m[num]++;
      }
      
      for(auto num:nums1) {
        m[num]--;
      }
      
      for(auto val:m) {
        if(val.second>0)
          output.push_back(val.first);
      }
      return output;
    }
};