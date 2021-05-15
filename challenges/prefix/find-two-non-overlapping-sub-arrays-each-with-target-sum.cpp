// https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
      int n=arr.size(), sum=0, diff;
      unordered_map<int,int> m;
      m[0] = -1;
      for(int i=0;i<arr.size();i++) {
        sum+=arr[i];
        m[sum]=i;
      }
      int l1 = sum+1, l2 = sum+1, maxSum=sum+1;
      sum=0;
      
      for(int i=0;i<arr.size();i++) {
        sum+=arr[i];
        if( m.find(sum - target) !=m.end() ) {
          l1 = min(l1, i-m[sum - target]);
        }
        
        if( m.find(sum + target) !=m.end() && l1!=maxSum) {
          l2 = min(l2, l1 + m[sum + target]-i); 
        }
        
        
      }
      
      if(l2 == maxSum) return -1;
      return l2;
    }
};