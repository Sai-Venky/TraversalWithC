// https://leetcode.com/problems/car-fleet/

/*
    class Solution {
        public:
            int carFleet(int target, vector<int>& position, vector<int>& speed) {
                
                vector<pair<int,double>> pos_time; // to store time taken by car at postion p to reach target
                
                int n = position.size();
                
                for(int i=0;i<n;i++) {
                    int p = position[i];
                    int s = speed[i];
                    
                    pos_time.push_back({p, (double)(target - p)/s});
                }
                
                sort(pos_time.begin(), pos_time.end());
                
                
                int car_fleets = 0;
                double time_spent = 0;
                
                for(int i = n-1;i>=0;i--) {
                    auto cur_car = pos_time[i];
                    double time_required_by_cur_car = cur_car.second;
                    
                    double time_left =  time_required_by_cur_car - time_spent;
                    
                    if(time_left>0) { // this means that cur_car does not collide with any car in front of it
                        car_fleets++;
                        time_spent +=time_left;
                    } 
                    
                }
                return car_fleets;
            }
        };
*/

class Solution {
public:
    int find(vector<int> & parent, int i) {
      if(parent[i]==i) return i;
      parent[i] = find(parent, parent[i]);
      return parent[i];
    }
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
      vector<pair<int, int>> v;
      int n=position.size(), out=0;
      vector<int> parent(n, -1);
      for(int i=0;i<n;i++) {
        parent[i]=i;
        v.push_back({position[i], speed[i]});
      }
      sort(v.begin(), v.end());
      
      for(int i=n-1;i>=1;i--) {
        int index=find(parent, i);
        double first=double(target-v[index].first)/v[index].second; 
        double sec=double(target-v[i-1].first)/v[i-1].second; 
        if(sec<=first) {
          int l=find(parent, i);
          int r=find(parent, i-1);
          parent[r]=l;
        }
      }

      for(int i=0;i<n;i++) {
        if(parent[i]==i) out++;
      }
      
      return out; 
    }
};