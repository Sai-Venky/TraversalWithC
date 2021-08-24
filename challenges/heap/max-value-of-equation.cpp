// https://leetcode.com/problems/max-value-of-equation

// Note the use of heap here and y-x logic.

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& pts, int k) {
        priority_queue<pair<int, int>> pq; // max-heap
        pq.push({pts[0][1]-pts[0][0],pts[0][0]});
        int ans= INT_MIN;
        for(int i=1;i<pts.size();i++) {
            int sum = pts[i][0]+pts[i][1];
            while(!pq.empty() && pts[i][0]-pq.top().second>k) pq.pop();
            if(!pq.empty())ans = max(ans,sum+pq.top().first);
            pq.push({pts[i][1]-pts[i][0],pts[i][0]});
        }
        return ans;
    }
};

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        //(y-x, x)
        deque<vector<int>> deq;
        
        int ans = INT_MIN;
        
        for(vector<int>& point : points){
            int x = point[0], y = point[1];
            
            while(!deq.empty() && x - deq.front()[1] > k){
                deq.pop_front();
            }
            
            if(!deq.empty()){
                ans = max(ans, deq.front()[0] + (y + x));
            }
            
            /*
            keep the deque decreasing(fronter element has larger y-x)
            the element before current point must have larger y-x
            */
            while(!deq.empty() && deq.back()[0] <= y - x){
                deq.pop_back();
            }
            
            deq.push_back({y-x, x});
        }
        
        return ans;
    }
};