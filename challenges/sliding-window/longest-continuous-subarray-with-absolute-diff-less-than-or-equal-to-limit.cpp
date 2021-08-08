// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

/*  
  Logic - SF
  Code  - SW. note the use of rbegin and begin
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> m;
        int j=0,ans=1;
        for(int i=0;i<nums.size();i++)
        {
            m.insert(nums[i]);
            while(!m.empty() && *m.rbegin()-*m.begin()>limit)
                m.erase(m.find(nums[j++]));
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};