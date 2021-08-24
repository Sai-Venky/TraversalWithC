// https://leetcode.com/problems/heaters/

/*
  Code - BS
  Logic - NOte the logic here. For each house find left and right heater and keep track of maximum.
  Another solution - https://leetcode.com/problems/heaters/discuss/95887/C%2B%2B-clean-solution-with-explanation
    int findRadius(vector<int>& A, vector<int>& H) {
      sort(A.begin(), A.end());
      sort(H.begin(), H.end());
      vector<int> res(A.size(), INT_MAX); 
      
      // For each house, calculate distance to nearest RHS heater
      for (int i = 0, h = 0; i < A.size() && h < H.size(); ) {
          if (A[i] <= H[h]) { res[i] = H[h] - A[i]; i++; }
          else { h++; }
      }
      
      // For each house, calculate distance to nearest LHS heater
      for (int i = A.size()-1, h = H.size()-1; i >= 0 && h >= 0; ) {
          if (A[i] >= H[h]) { res[i] = min(res[i], A[i] - H[h]); i--; }
          else { h--; }
      }
      
      return *max_element(res.begin(), res.end());
    }
  };
*/

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