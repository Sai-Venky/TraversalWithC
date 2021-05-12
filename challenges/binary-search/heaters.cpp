// https://leetcode.com/problems/heaters/

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
      sort(houses.begin(), houses.end());
      sort(heaters.begin(), heaters.end());
      int r=0;
      
      for(auto house:houses) {
        int l=0, h=heaters.size()-1;

        while(l+1<h) {
          int m=l+(h-l)/2;

          if(heaters[m] > house) {
            h=m;
          } else {
            l=m;
          }
        }
        r = max({r, min(abs(house-heaters[l]), abs(house-heaters[h]))});
      }
      return r;
      
    }
};