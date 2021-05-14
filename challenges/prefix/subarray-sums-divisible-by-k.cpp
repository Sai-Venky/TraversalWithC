// https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
    
        unordered_map<int, int> mp;
                
        int runningSum=0,ct=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            runningSum+=nums[i];
            runningSum = runningSum%k;
            if(runningSum<0) runningSum+=k;
            ct+=mp[runningSum];
            mp[runningSum]+=1;
                    
        }
        
        return ct;
        
    }
};