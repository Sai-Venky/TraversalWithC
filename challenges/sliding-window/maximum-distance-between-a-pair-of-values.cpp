// https://leetcode.com/problems/maximum-distance-between-a-pair-of-values

/*  
  Logic - SF
  Code  - Sliding Window
*/

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
      int i=0, j=0;
      int dis=0;
      for(j=0;i<nums1.size() && j<nums2.size();j++) {
                 
        if(nums2[j]<nums1[i] ) {
          i++; 
        } else {
          dis = max(dis, j-i);
        }
        
      }
      return dis;
    }
};