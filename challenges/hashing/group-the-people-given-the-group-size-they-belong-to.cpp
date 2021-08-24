// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to

// SF

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> ump;
        vector<vector<int>> ans;
        int n = groupSizes.size();
        for(int i=0; i<n; ++i) {
            ump[groupSizes[i]].push_back(i);
            if(ump[groupSizes[i]].size() == groupSizes[i]) {
                ans.push_back(ump[groupSizes[i]]);
                ump[groupSizes[i]] = {};
            }
        }
        return ans;
    }
};