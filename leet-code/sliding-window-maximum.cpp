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