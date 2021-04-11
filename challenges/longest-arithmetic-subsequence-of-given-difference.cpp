// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int res = 1;
        unordered_map<int,int> maxmap;
        for(int i = 0 ; i < arr.size() ; i++){
            maxmap[arr[i]] = maxmap[arr[i]-diff]+1;
            res = max(res,maxmap[arr[i]]);
        }
        return res;
    }
};