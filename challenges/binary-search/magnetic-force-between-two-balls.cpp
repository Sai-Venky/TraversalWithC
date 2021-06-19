// https://leetcode.com/problems/magnetic-force-between-two-balls/
// https://leetcode.com/problems/magnetic-force-between-two-balls/discuss/794066/Simple-Explanation

class Solution {
public:
    bool isPossible(vector<int>& position, int m, int mo) {
      int s=position[0], no=1;
      for(int i=1;i<position.size();i++) {
        if(position[i]-s>=m) {
          s=position[i];
          no++;
        }
        
      }
      if(no>=mo) return true;
      return false;
      
    }
  
    int maxDistance(vector<int>& position, int mo) {
      sort(position.begin(), position.end());
      int m, l=1, h=position[position.size()-1];
      
      while(l<=h) {
        m = l + (h-l)/2;
        bool p = isPossible(position, m , mo);
        if(p) {
          l=m+1;
        } else {
          h=m-1;
        }
        
      }
      return h;
    }
};