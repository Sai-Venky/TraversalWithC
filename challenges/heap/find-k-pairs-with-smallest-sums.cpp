// https://leetcode.com/problems/find-k-pairs-with-smallest-sums

/*
  Code  - SF
  Logic - Heap. Note the use of pushing all elements in the beginning to avoid duplicates 2,3 and 3,2 to 3,3 cases
*/
// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/discuss/84551/simple-Java-O(KlogK)-solution-with-explanation
// The run time complexity is O(kLogk) since que.size <= k and we do at most k loop.
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> res;
        if (m == 0 || n == 0) return res;
        for (int i = 0; i < m; i++) {
            pq.push({{nums1[i]+nums2[0]}, {i, 0}});
        }
        while (!pq.empty() && k-- > 0) {
            int val = pq.top().first, i = pq.top().second.first, j = pq.top().second.second;
            pq.pop();
            vector<int> v = {nums1[i], nums2[j]};
            res.push_back(v);
            if (j+1 == n) continue;
            pq.push({{nums1[i]+nums2[j+1]}, {i, j+1}});
        }
        return res;
    }
};

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