// https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int checkHours(vector<int>& piles, int m) {
      int hr=0;
      for(int pile:piles) {
        if(pile%m == 0) {
          hr += (pile/m);
        } else {
          hr+= ((pile/m)+1);  
        }
      }
      return hr;
    }
    
    
    int minEatingSpeed(vector<int>& piles, int hr) {
      int l=1, n=piles.size();
      int h=0;
      for(auto pile:piles) {
        if(pile>h) h=pile;
      }
      
      
      while(l<=h) {
        int m = l + ((h-l)/2);
        int hours = checkHours(piles, m);
        if(hours > hr) {
          l = m+1;
        } else {
          h = m-1;
        }

      }
      return l;
      
      
    }
};

