// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted

// Note the 2 sum pointer approach here where both l, r is incremented together
// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/solutions/830480/c-o-n-sliding-window-explanation-with-illustrations/
class Solution {
public:

    int findLengthOfShortestSubarray(vector<int>& arr) {
      int n=arr.size();
      int l=0, r=n-1;
      for(;l<r;l++) if(arr[l+1]<arr[l]) break;
      if(l==r) return 0;
      for(;r>l;r--) if(arr[r-1]>arr[r]) break;

      int out=min(n-l-1, r);

      for(int i=0;i<=l;i++) {
        while(r<n && arr[i]>arr[r]) {
          r++;
        }
        out=min(out, r-i-1);
      }
    
      return out;
    }
};