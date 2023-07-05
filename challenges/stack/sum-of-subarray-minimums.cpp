// https://leetcode.com/problems/sum-of-subarray-minimums

https://leetcode.com/problems/sum-of-subarray-minimums/discuss/178876/stack-solution-with-very-detailed-explanation-step-by-step

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        vector<int> s;
        long res = 0, mod = 1e9 + 7;
        int n=arr.size();
        vector<int> left(n, 0), right(n, 0);

        for(int i=0;i<n;i++) {
            while(!s.empty() && arr[s.back()] > arr[i]) {
                s.pop_back();
            }
            left[i] = s.empty() ? i+1 : i-s.back();
            s.push_back(i);
        }
        s.clear();
        for(int i=n-1;i>=0;i--) {
            while(!s.empty() && arr[s.back()] >= arr[i]) {
                s.pop_back();
            }
            right[i] = s.empty() ? n-i : s.back()-i;
            s.push_back(i);
        }


        for(int i=0;i<n;i++) {
            res = (res + (long)arr[i] * left[i] * right[i]) % mod;
        }
        return res;
    }
};