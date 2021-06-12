// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
            
      map<int, int> m;
      int n=nums.size();
      
      for(int i=0;i<n; i++) {
        m[nums[i]]++;
      }
      
      while (m.size()!= 0) {
        int cur = m.begin()->first;
        
        for (int i = 0; i < k; i++) {
          if(m[cur+i] ==0) return false;
          else if(--m[cur+i] == 0) m.erase(cur+i);
        }
        

      }
      return true;
    }
};