// https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

class Solution {
public:
    bool isPossible(vector<int>& dist, double hour, int m) {
      double hr=0;
      int i;
      for(i=0;i<dist.size()-1;i++) {
        hr+=ceil(double(dist[i])/m);
      }
      hr+=double(dist[i])/m;
      return hr<=hour;
    }
  
    int minSpeedOnTime(vector<int>& dist, double hour) {
      
      int totalDist=0;
      if (hour <= (double)(dist.size() - 1))
            return -1;
      int l=1, h=1e7;
      
      while(l<h) {
        int m=l+(h-l)/2;
        if(isPossible(dist, hour, m)) {
          h=m;
        } else {
          l=m+1;
        }
      }
      return l;
    }
};