// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
      int n=bloomDay.size();
      int ct=0, total = (m*k);
      if(n<total) return -1;
      int low=bloomDay[0],high=bloomDay[0];
      
      for(auto day: bloomDay) {
        if(low>day) low=day;
        if(high<day) high=day;
      }
      
      int result = -1;
      while(low<=high) {
        int mid = low + (high-low)/2;
        int flow=0, ct=0;

        for(int i=0;i<n;i++) {
          if(bloomDay[i] <= mid) {
            flow++;
          } else {
            flow=0;
          }
          if(flow==k) {
            ct++;
            flow=0;
          }
          
        }
        if(ct<m) {
          low=mid+1;
        } else {
          high=mid-1;
        }
        if(ct>=m) result = mid;
        
        
      }
      return result;
    }
};