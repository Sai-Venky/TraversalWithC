// https://leetcode.com/problems/image-overlap

/*

    Note the use of string to capture the diff here.
    for each one in img1, the distance of that with all other ones are calculated.
    Intuition
    Assume A and B are 3 * 3 matrix.:
    A:
    1,0,1
    1,0,0
    1,1,1
    B:
    0,0,1
    0,1,1
    1,1,1
    Flatten each of them to 1-D array:
    flattened idx: 0,1,2,3,4,5,6,7,8
    flattened A: 1,0,1,1,0,0,1,1,1 -> 0,2,3,6,7,8 : LA
    flattened B: 0,0,1,0,1,1,1,1,1 -> 2,4,5,6,7,8 : LB
    Each '1' in A can be overlapped with each '1' in B for different offset.
    Iterate through every overlap situation for '1' (at i) in LA and '1' (at j) in LB, group by offset (i - j).
    Final step is to find the largest number of overlapped '1's among all offsets.
*/

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
      int n=img1.size();
      
      vector<pair<int, int>> p1, p2;
      for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
          if(img1[i][j]) p1.push_back({i, j});
          if(img2[i][j]) p2.push_back({i, j});
        }
      }
      
      unordered_map<string, int> m;
      for(auto p1v: p1) {
        for(auto p2v: p2) {
          string diff = to_string(p1v.first-p2v.first) + "_" + to_string(p1v.second-p2v.second);
          m[diff]++;
        }
      }
      int ct=0;
      for(auto v:m) ct=max(ct, v.second);
        
      return ct;
    }
};