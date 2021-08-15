// https://leetcode.com/problems/sliding-window-maximum

class Solution {
public:
    
    class Monoqueue {
      
        deque<int> q;
        
        public:
        void push(int num) {
            
            while(!q.empty() && num > q.back()) {
                q.pop_back();   
            }
            q.push_back(num);
        }
        
        int max() {
            return q.front();
        }
        
        void pop(int num) {
            if(!q.empty() && q.front() == num) {
                q.pop_front();
            }
        }
        
    };
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Monoqueue mq;
        vector<int> results;
        for(int i=0; i<nums.size(); i++) {
            if(i < k -1) {
                mq.push(nums[i]);
            } else {
                mq.push(nums[i]);
                results.push_back(mq.max());
                mq.pop(nums[i-k+1]);
            }
        }
        
        return results;
    }
};

/*

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      deque<int> q;
      vector<int> out;
      int max=0, i=0;
      for(;i<k;i++) {
        while(!q.empty() && nums[i]>nums[q.back()]) {
          q.pop_back();
        }
        q.push_back(i);
      }
      out.push_back(nums[q.front()]);
      
      for(;i<nums.size();i++) {
        while(!q.empty() && nums[i]>nums[q.back()]) {
          q.pop_back();
        }
        q.push_back(i);
        while(!q.empty() && q.front()<i-k+1) {
          q.pop_front();
        }
        out.push_back(nums[q.front()]);
        
      }
      return out;
    }
};

*/