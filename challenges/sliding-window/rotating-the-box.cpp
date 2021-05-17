// https://leetcode.com/problems/rotating-the-box

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
      int m=box.size();
      int n=box[0].size();
      vector<vector<char>> rot(n, vector<char>(m, '.'));
      for(int i=m-1;i>=0;i--) {
        
        int l=0, h=0, ct=0;
        while(true) {
          if(l>=n) break;
          if(h==n || box[i][h] == '*') {
            if(l==h && h!=n) {
              rot[l++][m-i-1]='*';
              h++;
              ct=0;
            } else if(l>=h-ct) {
              rot[l++][m-i-1]='#';
            } else {
              rot[l++][m-i-1]='.';            
            }
            
            continue;
          } else if(box[i][h] == '#') {
            ct++;
          }
          h++;
        }
        
        
      }
      return rot;
      
    }
};