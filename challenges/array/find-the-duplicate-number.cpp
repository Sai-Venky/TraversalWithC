// https://leetcode.com/problems/find-the-duplicate-number

/*
int findDuplicate(vector<int>& nums) {
    int n=nums.size()-1;
    int low=1;
    int high=n;
    int mid;
    while(low<high){
        mid=(low+high)/2;
        int count=0;
        for(int num:nums){
            if(num<=mid) count++;
        }
        if(count>mid) high=mid;
        else low=mid+1; 
    }
    return low;
}
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      int n=nums.size(), i;
      for(i=0; i<n; i++) {
        int mod=nums[i]%n;
        mod=mod<0?mod*-1:mod;
        if(nums[mod-1]<0) {
          break;
        }
        nums[mod-1]=-1*nums[mod-1];
      }
      return nums[i]>0?nums[i]:-1*nums[i];
    }
};