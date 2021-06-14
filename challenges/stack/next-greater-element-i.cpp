// https://leetcode.com/problems/next-greater-element-i

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      
      stack<int> s;
      unordered_map<int, int> m;
      
      for(int num:nums2) {
        
        while(!s.empty() && s.top()<num) {
          m[s.top()] = num;
          s.pop();
        }
        s.push(num);
      }
      
      vector<int> out;
      for(int num:nums1) {
        out.push_back(m.count(num) ? m[num] :-1);
      }
      return out;
    }
};