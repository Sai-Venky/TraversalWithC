// https://leetcode.com/problems/next-greater-element-ii

/*  
    Logic - SF. Note the use of n*2 by mod for similifying code
    Code - Stack
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& A) {
        int n = A.size();
        vector<int> stack, res(n, -1);
        for (int i = 0; i < n * 2; ++i) {
            while (stack.size() && A[stack.back()] < A[i % n]) {
                res[stack.back()] = A[i % n];
                stack.pop_back();
            }
            stack.push_back(i % n);
        }
        return res;
    }
};