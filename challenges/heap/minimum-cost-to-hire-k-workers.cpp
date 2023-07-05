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
     
      /*
      Why do we choose the highest quality person to remove? Why not choosing other workers?
      Answer:
      Since the workers are sorted in the increasing order of the wage/quality ratio, the global ratio will never decrease. For the previously scanned wrokers, we do not care about their personal ratios any more because their personal ratios will always be less than (or equal to) the current global ratio. So the previous workers' personal ratio will never affect the total payment.
      Similarly, their personal base payment (i.e. the wage input) has been satisfied already. As the global ratio increases, their actual payemnt will only increase or stay the same, and will never become lower than their base payment.
      So when deciding whom to remove, the only thing that matters is the workers' quality. With a given global ratio, removing the highest quality worker will reduces the total payment as much as possible. That is why we want to removing the highest quality worker.
      */
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