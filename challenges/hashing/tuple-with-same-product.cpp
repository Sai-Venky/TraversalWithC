// https://leetcode.com/problems/tuple-with-same-product

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
      unordered_map<int, int> m; 
      int out=0;
      for(int i=0;i<nums.size(); i++) {
        for(int j=i+1;j<nums.size(); j++) {
          m[nums[i]*nums[j]]++;
        }
      }
      for(auto v:m) {
        out+= 4*v.second*(v.second-1);
      }
      return out;
    }
};