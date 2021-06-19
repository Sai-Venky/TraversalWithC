// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> dups;
        for(auto num:nums) {
            if(dups.find(num) != dups.end()) return true;
            dups.insert(num);
        }
        return false;

    }
};