// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

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