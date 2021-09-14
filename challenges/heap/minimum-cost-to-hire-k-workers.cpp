// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/

// Note the intuition of using ratio here. https://leetcode.com/problems/minimum-cost-to-hire-k-workers/discuss/141768/Detailed-explanation-O(NlogN)

class Solution {
public:
    static bool comp(pair<double, int> a, pair<double, int> b) {
      return a.first<b.first;
    }
  
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
      int n=quality.size(), qualitycnt=0;      
      
      vector<pair<double, int>> records;
      priority_queue<double> q;
      
      for(int i=0;i<n;i++) records.push_back( {double(wage[i])/quality[i], quality[i]} );
      sort(records.begin(), records.end(), comp);
      
      for(int i=0;i<k;i++) {
        qualitycnt+=records[i].second;
        q.push(records[i].second);
      }
      double out=qualitycnt*records[k-1].first;
     
      for(int i=k;i<n;i++) {
        q.push(records[i].second);
        qualitycnt+=records[i].second;
        qualitycnt-=q.top();
        q.pop();
        out=min(out, qualitycnt*records[i].first);
      }
      
      return out;
    }
};