// https://leetcode.com/problems/median-of-two-sorted-arrays

// Note the us of BS here.
/*
  [1, 2, 3, 4, 5, 6]
  [4, 7, 7, 7, 8]

*/
class Solution {
  
    int binarysearch(vector<int>& nums1, vector<int>& nums2, int pos, int s1, int e1, int s2, int e2) {
      if (s1 > e1) return nums2[s2 + pos - 1];
      if (s2 > e2) return nums1[s1 + pos - 1];
      int m1 = (s1+e1)/2;
      int m2 = (s2+e2)/2;
      
      if((m1-s1)+(m2-s2)+1>=pos) {
        if(nums1[m1]<=nums2[m2]) {
          return binarysearch(nums1, nums2, pos, s1, e1, s2, m2-1);
        } else {
          return binarysearch(nums1, nums2, pos, s1, m1-1, s2, e2);          
        }
      } else {
        if(nums1[m1]<=nums2[m2]) {
          return binarysearch(nums1, nums2, pos-(m1-s1)-1, m1+1, e1, s2, e2);
        } else {
          return binarysearch(nums1, nums2, pos-(m2-s2)-1, s1, e1, m2+1, e2);          
        }
      }
      
    }
  
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int n=nums1.size(), m=nums2.size();
      int k = (n + m + 1) / 2;

      int num1 = binarysearch(nums1, nums2, k, 0, n-1, 0, m-1);
      if ((n + m) & 1) return num1;

      int num2 = binarysearch(nums1, nums2, k+1, 0, n-1, 0, m-1);
      return (num1 + num2) / 2.0;
    }
};