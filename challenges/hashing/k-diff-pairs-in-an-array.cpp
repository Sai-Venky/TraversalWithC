// https://leetcode.com/problems/k-diff-pairs-in-an-array/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(auto num:nums)
            map[num]++;
        
        int res = 0;
        if (k > 0) {
            for(auto a:map)
                if (map.find(a.first+k) != map.end()) 
                    res++;
        }
        // In the case of unique
        else {
            for(auto a:map)
                if (a.second > 1)
                    res++;
        }
        
        return res;
    }
};