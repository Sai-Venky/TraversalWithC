// https://leetcode.com/problems/k-th-smallest-prime-fraction/

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
      
      priority_queue<pair<float, pair<int, int>>, vector<pair<float, pair<int, int>>>, greater<pair<float, pair<int, int>>>> q;
      int n=arr.size();
      vector<int> small;
      
      while(k) {
        
        for(int i=0;i<n-1;i++) {
          q.push({float(arr[i])/arr[n-1], {arr[i],arr[n-1]} });
        }
        pair<float, pair<int, int>> p =q.top();
        small = vector<int>{p.second.first, p.second.second};
        q.pop();
        k--;
        n--;
      }
      
      return small;
    }
};