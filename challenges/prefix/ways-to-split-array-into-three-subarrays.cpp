// https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
      vector<int> prefix = nums;
      int n=nums.size(), s =prefix[0];
      for(int i=1;i<n;i++) {
        prefix[i] +=s;
        s=prefix[i];
      }
      int ans=0;
      for(int i=1;i<n;i++) {
        if(prefix[n-1]-prefix[i-1] < 2 * prefix[i-1]) break;
        
        int l=findl(prefix, i-1, i);
        int r=findr(prefix, i-1, i);
        if (l == -1 || r == -1) continue;  

        ans+=r-l+1;
      }
      return ans%(1000000007);
    }
  
    int findl(vector<int> prefix, int i, int l) {
      
      int h=prefix.size()-2;
      int r=0;
      while(l<=h) {
        int m=l+(h-l)/2;
        
        if(prefix[m]-prefix[i]>=prefix[i]) {
          r=m;
          h=m-1;
        } else {
          l=m+1;
        }
      }
      return r;
    }
  
    int findr(vector<int> prefix, int i, int l) {
      int n =prefix.size();
      int h=n-2;
      int r=0;
      while(l<=h) {
        int m=l+(h-l)/2;
        
        if(prefix[m]-prefix[i]<=prefix[n-1]-prefix[m]) {
          r=m;
          l=m+1;
        } else {
          h=m-1;
        }
      }
      return r;  
    }
};