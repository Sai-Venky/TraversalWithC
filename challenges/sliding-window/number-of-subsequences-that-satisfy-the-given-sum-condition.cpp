// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

// note the use of sort here in subsequence as its similar to subset and wont affect

class Solution {
public:
   int numSubseq(vector<int>& A, int target) {
        sort(A.begin(), A.end());
        int res = 0, n = A.size(), l = 0, r = n - 1, mod = 1e9 + 7;
        vector<int> pows(n, 1);
        for (int i = 1 ; i < n ; ++i)
            pows[i] = pows[i - 1] * 2 % mod;
        while (l <= r) {
            if (A[l] + A[r] > target) {
                r--;
            } else {
                res = (res + pows[r - l++]) % mod;
            }
        }
        return res;
    }
};

/*
class Solution {
    typedef long long int LL;
    LL MOD = 1e9 + 7;
    
    LL pow2(int n) {
        if (n == 0) return 1;
        if (n == 1) return 2;
        LL x = pow2(n / 2);
        x = x * x % MOD;
        if (n % 2 == 1) x = x * 2 % MOD;
        return x;
    }
    
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= target) break;
            int pos = upper_bound(nums.begin(), nums.end(), target - nums[i]) - nums.begin() - 1;
            if (pos >= i)
                ans = (ans + pow2(pos - i) + MOD) % MOD;
        }
        return ans;
    }
};
*/