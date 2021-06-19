// https://leetcode.com/problems/count-nice-pairs-in-an-array

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
      long count = 0;
      unordered_map<int, long> mp;
      for(auto& num : nums) count = (count + mp[num - reverseNum(num)]++) % 1000000007;
      return count;
    }
    int reverseNum(int n){
      int revNum = 0;
      while(n) revNum = revNum * 10 + (n % 10), n /= 10;
      return revNum;
    }
};