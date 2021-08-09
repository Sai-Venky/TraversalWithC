// https://leetcode.com/problems/maximum-average-pass-ratio/

// Note the increment in denominator also here.

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
      
      priority_queue<pair<double, int>> q;
      
      for(int i=0;i<classes.size();i++) {
        double gain = ((double(classes[i][0]+1))/(classes[i][1]+1))  - (double(classes[i][0])/classes[i][1]);
        q.push(make_pair(gain, i));
      }
           
      while(extraStudents>0) {
        pair<double, int> p = q.top();q.pop();
        int i = p.second;
        classes[i][0] = classes[i][0]+1;
        classes[i][1] = classes[i][1]+1;
        double gain = ((double(classes[i][0])+1)/(classes[i][1]+1))  - (double(classes[i][0])/classes[i][1]);
        q.push(make_pair(gain, i));
        extraStudents--;
      }
      
      double av=0;
      for(auto cl:classes) {
        av+= (double(cl[0])/cl[1]);
      }
      
      return av/classes.size();
                      
    }
};