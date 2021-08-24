// https://leetcode.com/problems/delete-and-earn/

class Solution {
public:
	int deleteAndEarn(vector<int>& nums) {
		vector<int> cnt(10002);
		for(int i=0;i<nums.size();i++)
		{
			cnt[nums[i]]+=nums[i];
		}

		vector<int> dp(10002);
		dp[1]=cnt[1];
		dp[2]=max(cnt[1],cnt[2]);
		for(int i=3;i<dp.size();i++)
		{
			dp[i]=max(dp[i-2]+cnt[i],dp[i-1]);
		}

		return max(dp[10000],dp[9999]);
	}
};
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> sums;
        for (int num : nums) {
            sums[num] += num;
        }
        int take = 0, skip = 0;
        for (auto& p : sums) {
            if (sums.find(p.first - 1) == sums.end()) {
                skip = take;
                take += p.second;
            } else {
                int temp = max(skip + p.second, take);
                skip = take;
                take = temp;
            }
        }
        return take;
    }
};