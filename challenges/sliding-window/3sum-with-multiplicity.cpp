// https://leetcode.com/problems/3sum-with-multiplicity

/*  
  Logic - SF
  Code  - Using two pointers for each triplets. Ensuring duplicates are counted properly for multiplicity.
*/

class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target)  {
      int ct=0, mod=1e9+7;
      sort(nums.begin(), nums.end()); 

      for(int i=0; i<nums.size()-2; i++) {
        int start=i+1, end=nums.size()-1;
        while(start<end) {
          if(nums[start] + nums[end] + nums[i] == target) {
            long ctl=1, cth=1;
            while (start<end && nums[start]==nums[start+1]) {ctl++; start++;}
            while (start<end && nums[end]==nums[end-1]) {cth++; end--;}
            if(start==end) ct=(ct+ctl*(ctl-1)/2)%mod;
            else ct=(ct+ctl*cth)%mod;
            start++;end--;
          } else if (nums[start] + nums[end] + nums[i] > target) {
            end--;
          } else {
            start++;
          }
        }
      }
      return ct;
        
    }
};

//  Two Sum Number Of Ways
int numberOfWays(vector<int>& arr, int k) {
  // Write your code here
  
  sort(arr.begin(), arr.end());
  
  int l=0, h=arr.size()-1, ct=0;
  
  while(l<h) {
    int sum=arr[l]+arr[h];
    
    if(sum<k) {
      l++;
    } else if(sum>k) {
      h--;
    } else {
      int ll=1,hh=1;
      while(l<h && arr[l]==arr[l+1]) {ll++; l++;}
      while(l<h && arr[h]==arr[h-1]) {hh++; h--;}
      if(l==h) {ct+=((ll)*(ll-1)/2); break;}
      else ct+=(ll*hh);
      l++; h--;
      }
    }
   
   return ct;
}