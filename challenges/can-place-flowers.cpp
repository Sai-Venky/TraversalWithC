// https://leetcode.com/problems/can-place-flowers

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0;i<flowerbed.size();i++){
          int prev = i==0? 0: flowerbed[i-1];
          int cur = flowerbed[i];
          int next = i==flowerbed.size()-1? 0:flowerbed[i+1];
          if(!(prev || cur || next)) {
            flowerbed[i]=1;
            n--;
          }
        }
      return n<=0?true:false;
    }
};