// https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones

// https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/discuss/987607/O(n)-explanation-with-picture

// Note the storage of ones here and then computation being done.
// Note the presum part. the explanation for that is in the picture above.
// The 3 innovations here are ones storage, prefix identification and the fact that keep a rolling sliding window
// where the mid is always the best place to move all the ones to.

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

/*
#define ll long long

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        
        vector<ll> ones;
        vector<ll> prefix;
        ll ret = 1e18;

        for(int i=0;i<nums.size();i++) {
            if(nums[i])
            ones.push_back(i);
        }

        int sum=0;
        prefix.push_back(0);

        for(int i=0;i<ones.size();i++) {
            sum+=ones[i];
            prefix.push_back(sum);
        }
        int r=k-1, l=0;
        while(r<ones.size()) {

            int m = (l+r)/2;
            int left = m-l;
            int right = r-m;

            int moves = prefix[r+1] - prefix[m+1] - (prefix[m] - prefix[l]);
            int subtract = (left * (left+1) + right * (right+1))/2;

            if(k % 2 == 0) {   
                subtract += ones[m];  
            }

            if(moves - subtract < ret) {
                ret = moves - subtract;
            }
            l++;
            r++;
        }

        return ret;
    }
};
*/