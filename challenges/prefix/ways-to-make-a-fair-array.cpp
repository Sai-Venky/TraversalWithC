// https://leetcode.com/problems/ways-to-make-a-fair-array

/*

    1. Taking the sym for odd and even in reverse order.
    2. Considering sum from start and the array 
        Your input
        [2,1,6,4]
        stdout
        E 8 6 6 0 0 
        O 5 5 4 4 0 
*/
class Solution {
public:
    int waysToMakeFair(vector<int>& A) {
        int N = A.size(), even = 0, odd = 0, ans = 0;
        vector<int> e(N + 1), o(N + 1);
        for (int i = N - 1; i >= 0; --i) {
            if (i % 2 == 0) e[i] += A[i];
            else o[i] += A[i];
            e[i] += e[i + 1];
            o[i] += o[i + 1];
        }

        for (int i = 0; i < N; ++i) {
            ans += (even + o[i + 1]) == (odd + e[i + 1]);
            if (i % 2 == 0) even += A[i];
            else odd += A[i];
        }
        return ans;
    }
};