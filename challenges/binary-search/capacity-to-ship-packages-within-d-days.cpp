// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

/*
  Code - BS
  Logic - We dig out the monotonicity of this problem: if we can successfully ship all packages within D days with capacity m, then we can definitely ship them all with any capacity larger than m
*/

class Solution {
public:
    bool isPossible(vector<int>& weights, int cap, int D) {
      int sum=0;
      for(auto weight:weights) {
        if(sum+weight<=cap) {
          sum+=weight;
        } else {
          D--;
          if(D==0) return false;
          sum = weight;
        }
      }
      return true;
    }
  
    int shipWithinDays(vector<int>& weights, int D) {
      
      int low=0, high=0;
      for(auto weight:weights) {
        if(weight>low)low=weight;
        high+= weight;
      }

      int ship=0;
      while(low<=high) {
        
        int mid=low + (high-low)/2;
        if(isPossible(weights, mid, D)) {
          ship = mid;
          high=mid-1;
        } else {
          low=mid+1;
        }
        
      }
      
      return ship;
    }
};