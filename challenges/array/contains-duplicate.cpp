// https://leetcode.com/problems/contains-duplicate

// SF
/*
public boolean containsDuplicate(int[] nums) {

    final Set<Integer> distinct = new HashSet<Integer>();
    for(int num : nums) {
        if(distinct.contains(num)) {
            return true;
        }
        distinct.add(num);
    }
    return false;
}
*/
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