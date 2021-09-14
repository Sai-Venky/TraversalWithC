// https://leetcode.com/problems/merge-triplets-to-form-target-triplet/

// SF

/*
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& t) {
        vector<int> res(3);
        for (auto &s : triplets)
            if (s[0] <= t[0] && s[1] <= t[1] && s[2] <= t[2])
                res = { max(res[0], s[0]), max(res[1], s[1]), max(res[2], s[2]) };
        return res == t;
    }
*/
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
      
      bool a=false, b=false, c=false;
      for(auto triplet:triplets) {
        if(triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]) {
          if(triplet[0]==target[0])  a=true;
          if(triplet[1]==target[1])  b=true;
          if(triplet[2]==target[2])  c=true;
        }
      }
      return a && b && c;
    }
};

