// https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/

// SF

class Solution {
public:
    
    int fetchSum(vector<int>& arr, int m) {
      int sum=0, i;
      for(i=0;i<arr.size();i++) {
        if(arr[i] >= m) {
          sum+=m;     
        } else {
          sum+=arr[i];
        }
      }
      return sum;
      
    }
    
    int findBestValue(vector<int>& arr, int target) {
      int l=0, h=0;
      for(auto valu:arr) {
        if(valu>h) h = valu;
      }
      int dist = INT_MAX, t;
      
      while(l<=h) {
        int m= l+(h-l)/2;    
        int val = fetchSum(arr, m);
        
        int mid = abs(val - target);
        
        if(val>=target) {
          h = m-1;
        } else {
          l = m+1;
        }
        
        if(mid < dist) {
          dist = mid;
          t = m;
        } else if (dist == mid && m<t) {
          dist = mid;
          t = m;
        } 
        
      } 
      
      return t;
    }
};
