// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

/* 
    Code - SW
    Logic - SF
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      int l=0, h=numbers.size()-1;
      vector<int> out;
      while(l<=h) {
        if(l!=h && numbers[l] + numbers[h] == target) {
          out = vector<int>{l+1, h+1};
          break;
        } else if(numbers[l] + numbers[h] > target) {
          h--;
        } else {
          l++;
        }
      }
      return out;
    }
};