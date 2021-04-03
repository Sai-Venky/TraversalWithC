// https://leetcode.com/problems/richest-customer-wealth

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
      int max = 0;
      for(auto account :accounts){
        int tempMax = 0;
        for(auto value:account) {
          tempMax+=value;
        }
        if(tempMax>max) {
          max = tempMax;
        }
      }
      return max;
    }
};