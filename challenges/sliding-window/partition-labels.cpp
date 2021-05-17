// https://leetcode.com/problems/partition-labels/

/*
    1. Store a map with the maximum position of characters.
    2. Then if its equal to maximum , return
*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
      int l=0, h=s.length();
      map<char, int> m;
      vector<int> output;
      
      for(int i=0;i<h;i++) {
        m[s[i]]=i;
      }
      int max=0, start=0;
      while(l<=h) {
        
        max = m[s[l]]>max?m[s[l]]:max;
        
        if(max==l) {
          output.push_back(l-start+1);
          start=l+1;
        }
        l++;
      }
      return output;
    }
};

