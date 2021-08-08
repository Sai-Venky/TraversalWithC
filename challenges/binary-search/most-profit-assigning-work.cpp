// https://leetcode.com/problems/most-profit-assigning-work

/*
    O(DlogD + WlogW)
*/
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
     
      vector<pair<int, int>> jobs;
      int maximum=0;     
      for(int i=0;i<profit.size();i++) {
        jobs.push_back({difficulty[i], profit[i]});
      }
      sort(jobs.begin(), jobs.end());
      for(int i=0;i<jobs.size();i++) {
        maximum=max(maximum, jobs[i].second);
        jobs[i].second = maximum;
      }

      int maxProfit=0;
      
      for(int i=0;i<worker.size();i++) {
        int l=0, h=jobs.size()-1, tmp=0;
        while(l<=h) {
          int m=l+(h-l)/2;
          if(jobs[m].first<=worker[i]) {
            tmp=max(tmp,jobs[m].second);
            l=m+1;	
          } else {
            h=m-1;          
          }

        }
        maxProfit+=tmp;
      }
      return maxProfit;
    }
};
