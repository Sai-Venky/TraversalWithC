// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

/*
    Note the use of Intuition where all elements are merged and then sliding window is applied on top of it.
    The grouping of elements is checked here.

    Firstly we merge k groups to one group, each number recoard it's group, eg:

    [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]

    after merged we got：
    [(0, 1), (4, 0), (5, 2), (9, 1), (10, 0), (12, 1), (15, 0), (18, 2), (20, 1), (22, 2), (24, 0), (26, 0), (30, 2)]

    and see only group, it's
    [1, 0, 2, 1, 0, 1, 0, 2, 1, 2, 0, 0, 2]

    we can slide window by group when current groups satifies condition and recoard min range.

    [1 0 2] 2 1 0 1 0 2 1 2 0 0 2    [0, 5]
    1 [0 2 1] 1 0 1 0 2 1 2 0 0 2    [0, 5]
    1 0 [2 1 0] 0 1 0 2 1 2 0 0 2    [0, 5]
    1 0 [2 1 0 1] 1 0 2 1 2 0 0 2    [0, 5]
    1 0 [2 1 0 1 0] 0 2 1 2 0 0 2    [0, 5]
    1 0 2 1 0 [1 0 2] 2 1 2 0 0 2    [0, 5]
    1 0 2 1 0 1 [0 2 1] 1 2 0 0 2    [0, 5]
    1 0 2 1 0 1 [0 2 1 2] 2 0 0 2    [0, 5]
    1 0 2 1 0 1 0 2 [1 2 0] 0 0 2    [20, 24]
    1 0 2 1 0 1 0 2 [1 2 0 0] 0 2    [20, 24]
    1 0 2 1 0 1 0 2 [1 2 0 0 2] 2    [20, 24]
*/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> ordered; // (number, group)
        for (size_t k = 0; k < nums.size(); ++k)
            for (auto n: nums[k]) ordered.push_back({n, k});
        sort(ordered.begin(), ordered.end());

        int i = 0, k = 0;
        vector<int> ans;
        unordered_map<int, int> count;
        for (size_t j = 0; j < ordered.size(); ++j) {
            if (! count[ordered[j].second]++) ++k;
            if (k == nums.size()) { 
                while (count[ordered[i].second] > 1) --count[ordered[i++].second]; // minialize range
                if (ans.empty() || ans[1] - ans[0] > ordered[j].first - ordered[i].first) {
                    ans = vector<int>{ordered[i].first, ordered[j].first};
                }
            }
        }

        return ans;
    }
};

/*
Heap Solution

    class Solution {
    public:
        vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q; 
        int min, max=INT_MIN;
        for(int i=0;i<nums.size();i++) {
            q.push({nums[i][0], {i, 0}});
            max=std::max(max, nums[i][0]);
        }
        
        vector<int> out = {q.top().first, max};
        
        while(true) {
            
            pair<int, pair<int, int>> p =q.top(); q.pop();
            if(max-p.first<out[1]-out[0]) {
            out[0]=p.first;
            out[1]=max;
            }
            
            if(p.second.second+1==nums[p.second.first].size()) break;
            q.push({nums[p.second.first][p.second.second+1], {p.second.first, p.second.second+1}});
            max=std::max(max, nums[p.second.first][p.second.second+1]);
        }
        
        return out;
        }
    };
/*