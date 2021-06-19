// https://leetcode.com/problems/max-chunks-to-make-sorted/


class Solution {
public:
  int maxChunksToSorted(vector<int>& arr) {
    int sum1 = 0, sum2 = 0, ans = 0;
    for(int i = 0; i < arr.size(); i++) {
        sum1 += i;
        sum2 += arr[i];
        if(sum1 == sum2)    ans++;
    }
	  return ans;
    }
};