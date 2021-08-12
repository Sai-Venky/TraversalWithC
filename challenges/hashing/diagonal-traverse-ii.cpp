// https://leetcode.com/problems/diagonal-traverse-ii

//  Note the use of map to store the array elements.

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
      vector<int> out;
      unordered_map<int, vector<int>> m;
      
      for(int i=nums.size()-1;i>=0;i--) {
        for(int j=0;j<nums[i].size();j++) {
          m[i+j].push_back(nums[i][j]);
        }
      }
      
      for(int i=0;i<m.size();i++) {
        for (int e : m[i]) out.push_back(e);
      }
     
      
      return out;
    }
};