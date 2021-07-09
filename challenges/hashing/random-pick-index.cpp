// https://leetcode.com/problems/random-pick-index/

/*
    class Solution {
        public:
            // unordered_map<int,vector<int>> mp;
            
            vector<int> arr;
            Solution(vector<int>& nums) {
            arr=nums;
            }
            
            int pick(int target) {
                
                //we are traversing the array again and storing the indices and then we pick a random index from it
                vector<int> indices;
                for(int i=0;i<arr.size();++i)
                {
                    if(arr[i]==target)
                        indices.push_back(i);
                }
                return indices[rand()%indices.size()];
            }
        };
*/

class Solution {
public:
    unordered_map<int, vector<int>> m;
    Solution(vector<int>& nums) {

      for(int i=0;i<nums.size();i++) {
          m[nums[i]].push_back(i);
      }
      for(auto itr = m.begin(); itr != m.end(); ++itr) {
        itr->second.push_back(0);
      }
    }
    
    int pick(int target) {
      int n=m[target].size();
      if( m[target][n-1]==n-1) {
         m[target][n-1]=0;
      }
      int index= m[target][ m[target][n-1]];
      m[target][n-1]++;
      return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */