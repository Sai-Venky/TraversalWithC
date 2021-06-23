// https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones

// https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/discuss/987607/O(n)-explanation-with-picture
#define ll long long

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        int i, n = nums.size(), l, r;
        vector<ll> a;   // Indexes array
        a.push_back(0); // Make indexes array the same size as prefix array
        for(i=0; i<n; i++)
            if(nums[i])
                a.push_back(i);
        n = a.size();
        vector<ll> pref(n, 0);  // Prefix array
        for(i=1; i<n; i++)     // prefix[i] = sum of all elements from a[0] to a[i - 1]
            pref[i] = a[i] + pref[i - 1];
        
        ll ret = 1e18;
        
        // Rolling window [l...r] of length k
        for(l=1,r=k; r<n; ++l, ++r) {
            int mid = (l + r) / 2;  // Mid-point - current element
            int radius = mid - l;   // How many elements on each side
            ll right = pref[r] - pref[mid];     // Prefix of radius elements to the right of mid
            ll left = pref[mid - 1] - pref[l - 1];  // Prefix of radius elements to the left of mid
            ll subtract = (radius) * (radius + 1);  // Once all elements are equal, make it a sequence
            if(k % 2 == 0) {        // Special case if k is even
                left += a[mid];     // Deduct current element
                subtract += (radius + 1);   // Deduct the cost of the furthest right element
            }
            ret = min(ret, right - left - subtract);
        }
        return ret;
    }
};