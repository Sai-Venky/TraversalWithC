// https://leetcode.com/problems/minimum-area-rectangle-ii

// Note the hashing of center and distance as string part

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
      double out=INT_MAX;
      unordered_map<string, vector<vector<int>>> m;

      for(int i=0;i<points.size();i++) {
        for(int j=i+1;j<points.size();j++) {
          long dist = (points[j][1] - points[i][1])*(points[j][1] - points[i][1]) + (points[j][0] - points[i][0])*(points[j][0] - points[i][0]);
          
          double ycen = double(points[j][1]+points[i][1])*0.5;
          double xcen = double(points[j][0]+points[i][0])*0.5;
          
          string key = to_string(dist) + '_' + to_string(xcen) + '_' + to_string(ycen);
          m[key].push_back({i, j});          
        }
      }
      
      for(auto v:m) {
        // cout<<v.first<<" "<<v.second.size()<<endl;
        
        if(v.second.size()>1) {
          
          for(int i=0;i<v.second.size();i++) {
            for(int j=i+1;j<v.second.size();j++) {
              int tl_x = points[v.second[i][0]][0], tl_y = points[v.second[i][0]][1];
              int br_x = points[v.second[i][1]][0], br_y = points[v.second[i][1]][1];
              int cur_x= points[v.second[j][0]][0], cur_y= points[v.second[j][0]][1];
              
              double len = sqrt(double(((cur_x-tl_x)*(cur_x-tl_x)) + ((cur_y-tl_y)*(cur_y-tl_y))));
              double bre = sqrt(double(((cur_x-br_x)*(cur_x-br_x)) + ((cur_y-br_y)*(cur_y-br_y))));
              double area = len * bre;
              out=min(out, area);
            }
          }
        }
        
      }
      
      
      return out==INT_MAX?0:out;
    }
};