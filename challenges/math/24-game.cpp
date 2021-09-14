// https://leetcode.com/problems/24-game/

// Note the intuition of dfs, checking division by 0 

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> a(nums.begin(), nums.end());
        return dfs(a);
    }
    vector<double> get(int i, int j, double c, vector<double>& nums) {
        vector<double> res;
        for (int k = 0; k < nums.size(); k ++) {
            if (k != i && k != j) {
                res.push_back(nums[k]);
            }
        }
        res.push_back(c);
        return res;
    }
    bool dfs(vector<double> nums) {
        if (nums.size() == 1) return fabs(nums[0] - 24) <= 1e-8;
        for (int i = 0; i < nums.size(); i ++)
            for (int j = 0; j < nums.size(); j ++) {
                if (i != j) {
                    double a = nums[i], b = nums[j];
                    if (dfs(get(i, j, a + b, nums))) return true;
                    if (dfs(get(i, j, a - b, nums))) return true;
                    if (dfs(get(i, j, a * b, nums))) return true;
                    if (b && dfs(get(i, j, a / b, nums))) return true;
                }
            }
        return false;
    }
};