// https://leetcode.com/problems/find-k-pairs-with-smallest-sums

class Solution {
public:
    struct Frequency {
      bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.first + p1.second < p2.first + p2.second;
      }
    };
  
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
      vector<vector<int>> output;
      priority_queue<pair<int, int>, vector<pair<int, int>>, Frequency > q;
      
      for(int i=0;i<nums1.size();i++) {
        for(int j=0;j<nums2.size();j++) {
          if(q.size()<k) {
            q.push(make_pair(nums1[i], nums2[j]));            
          } else if(q.top().first + q.top().second > nums1[i] + nums2[j]){
            q.pop();
            q.push(make_pair(nums1[i], nums2[j]));                        
          }
        }
      }
      
      while(!q.empty()){
            output.push_back({q.top().first, q.top().second});
            q.pop();
      }
      
      return output;
      
    }
};