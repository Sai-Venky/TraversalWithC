// https://leetcode.com/problems/partition-labels/

/*
    Logic - 
    1. Store a map with the maximum position of characters.
       /https://leetcode.com/problems/partition-labels/discuss/348059/C%2B%2B-O(n)-solution-with-explanation
    2. Then if its equal to maximum , return
    Code - The use of max to keep track of last occured characters maximum and ignoring other variables is good.
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

