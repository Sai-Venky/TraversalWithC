// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

// Good question to check logic
class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
      

      hc.insert(hc.begin(), 0);      
      hc.push_back(h);
      vc.insert(vc.begin(), 0);
      vc.push_back(w);
      sort(hc.begin(), hc.end());
      sort(vc.begin(), vc.end());
      int maxh=0, maxv=0;
      for(int i=1;i<hc.size();i++) {
        maxh=max(maxh, hc[i]-hc[i-1]);
      }
      
      for(int i=1;i<vc.size();i++) {
        maxv=max(maxv, vc[i]-vc[i-1]);
      }
      return (long(maxh)*maxv)%1000000007;
    }
};