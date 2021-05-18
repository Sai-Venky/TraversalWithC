// https://leetcode.com/problems/add-digits/

class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};