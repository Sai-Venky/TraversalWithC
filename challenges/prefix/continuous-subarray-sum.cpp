// https://leetcode.com/problems/continuous-subarray-sum/

// Store reminders and find the sums. Note the use of pre here to store sum one time later and ensure size greater than 1

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, pre = 0;
        unordered_set<int> modk;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int mod = k == 0 ? sum : sum % k;
            if (modk.count(mod)) return true;
            modk.insert(pre);
            pre = mod;
        }
        return false;
    }
};

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        if(nums.size()<2)
            return false;
                
        unordered_map<int, int> mp;
        
        // mp[0]=-1;
        
        int runningSum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            runningSum+=nums[i];
            runningSum = runningSum%k;
            if(runningSum==0&&i>0)return true; 
            else if (mp.find(runningSum)!=mp.end())
            {                
                if(i-mp[runningSum]>1 )
                    return true;
            }
            else mp[runningSum]=i;
                    
        }
        
        return false;
        
    }
};