// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/


/*
    NOte the logic here
    We have 4 plans:

    kill 3 biggest elements
    kill 2 biggest elements + 1 smallest elements
    kill 1 biggest elements + 2 smallest elements
    kill 3 smallest elements

*/

int minDifference(vector<int>& A) {
        int n = A.size();
        if (n < 5) return 0;
        sort(A.begin(), A.end());
        return min({A[n - 1] - A[3], A[n - 2] - A[2], A[n - 3] - A[1], A[n - 4] - A[0]});
    }