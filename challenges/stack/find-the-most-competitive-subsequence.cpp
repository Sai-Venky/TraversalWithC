// https://leetcode.com/problems/find-the-most-competitive-subsequence

/*
  Logic - Note the use of nums_to_delete. If nums_to_delete is 0, that means we cant delete any more elements else it would affect the size condition as there are no more elements left in array to fill.
  To fill the first slot, we should pick the smallest number between index [0] ~ [N-k] (inclusive) (we have to preserve at least k-1 numbers for the rest of k-1 slots)
    For the ith (0-indexed) slot, we should pick the smallest number between index [previous picked index + 1] ~ [N-k+i] (range of the window)
    We keep a increasing monotonic queue for the window, and use the smallest number (front of the queue)
  Code- Stack
*/

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> stack;
        int nums_to_delete = nums.size()-k;
        for (int i = 0; i < nums.size(); i++) {
            while (!stack.empty() && nums[i] < stack.back() && nums_to_delete) {
                stack.pop_back();
                nums_to_delete--;
            }
            stack.push_back(nums[i]);
        }
        return vector<int>(stack.begin(), stack.begin()+k);
    }
};