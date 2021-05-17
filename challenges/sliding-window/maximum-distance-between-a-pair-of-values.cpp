// https://leetcode.com/problems/maximum-distance-between-a-pair-of-values

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
      int i=0, j=0;
      int n=nums1.size(), m=nums2.size();
      int dis=0;
      while(true) {
        
        if(i==n||j==m) break;
                
        if(j<i ) {
          j++; 
          continue;
        }
        if(nums2[j]<nums1[i] ) {
          i++; 
          continue;
        }
        // cout<<i<<" "<<j<<"\n";
        dis = max(dis, j-i);
        j++;
      }
      return dis;
    }
};