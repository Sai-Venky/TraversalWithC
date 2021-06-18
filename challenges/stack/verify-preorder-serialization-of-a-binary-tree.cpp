// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree

class Solution {
public:
    bool isValidSerialization(string preorder) {
      
      vector<int> v;
      v.push_back(0);
      preorder.push_back(',');
      bool isNo=false;
      
      for(char c:preorder) {
        if(c==',' && !v.empty() ) {
          if(!isNo) continue;
          v.back()+=1;
          v.push_back(0);
          isNo=false;
        } else if(!v.empty() && c=='#') {
          v.back()+=1;
        } else {
          isNo=true;
        }
        while(!v.empty() && v.back() == 2) {
          v.pop_back();
        }
      }
      return !v.empty() && v.back() == 1 && v.size()==1;
      
    }
};