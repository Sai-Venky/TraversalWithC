// https://leetcode.com/problems/xor-operation-in-an-array/

class Solution {
public:
    int xorOperation(int n, int start) {
        int xorSum = start;

        for(int i=1; i<n; i++) {
            xorSum = xorSum ^ (start + 2*i);
        }
        return xorSum;
    }
};