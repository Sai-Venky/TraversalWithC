// https://leetcode.com/problems/maximum-distance-between-a-pair-of-values

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
      int i=0, j=0;
      int dis=0;
      while(true) {
        
        if(i==nums1.size()||j==nums2.size()) break;
                
        if(nums2[j]<nums1[i] ) {
          i++; 
          j++;
        } else {
          dis = max(dis, j-i);
          j++;
        }
        
      }
      return dis;
    }
};