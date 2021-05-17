// https://leetcode.com/problems/interval-list-intersections

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
      
      int f=0,s=0;
      int fn=firstList.size(), sn=secondList.size();
      vector<vector<int>> output;
      while(true) {
        if(f==fn||s==sn) break;
        vector<int> result;
        vector<int> col;
        vector<int> fi = firstList[f];
        vector<int> se = secondList[s];
        
        if(se[0] > fi[1]) {
          f++;
          continue;
        } else if(fi[0] > se[1]) {
          s++;
          continue;
        } else if(se[1] > fi[1]) {
          col.push_back(fi[1]);
          f++;
        } else {
          col.push_back(se[1]);
          s++;

        }
        col.push_back(fi[0]);
        col.push_back(se[0]); 
        sort(col.begin(), col.end());
        // cout<<f<<" "<<s<<" "<<col[1]<<" "<<col[2] <<"\n";
        result.push_back(col[1]);
        result.push_back(col[2]);
        output.push_back(result);
      }
      return output;
    }
};