// https://leetcode.com/problems/contiguous-array

/*
    class Solution {
    public:
        int findMaxLength(vector<int>& nums) {
        map<int, int> prefix;
        int o=0, e=0, out=0;
        prefix[0]=-1;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==0) e++;
            else o++;
            if(prefix.find(e-o)==prefix.end()) prefix[e-o]=i;
            else out=max(out, i-prefix[e-o]);
        }

        return out;
        }
    };
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      map<int, int> prefix;
      int sum=0, out=0;
      prefix[0]=-1;
      for(int i=0;i<nums.size();i++) {
        sum+=nums[i]?1:-1;
        if(prefix.find(sum)==prefix.end()) prefix[sum]=i;
        else out=max(out, i-prefix[sum]);
      }

      return out;
    }
};