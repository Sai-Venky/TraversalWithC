// https://leetcode.com/problems/text-justification/

// Note the various edge cases here
/*
    the len=-1 assignment
    k part and j-i-1 part

*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
      vector<string> out;      
      if(maxWidth == 0) return {""};
      for(int i=0,j=0;j<words.size();) {
        int len=-1;
        i=j;
        while(j<words.size() && len+words[j].length()+1<=maxWidth) {
          len+=words[j++].length()+1;
        }
        int space = maxWidth-len + (j-i-1);
        int k=i;
        while(space) {
          words[k++].push_back(' ');
          space--;
          if(k==j && j==words.size()) k=j-1;
          // For one word like maxwidth is 10 and its abcdefghij. In this case k becomes j directly
          // Or for multiple words and if its reaching end like abcd efgh ijkl, then got to beginning.
          // THis is to ensure last word dosent have space
          if((k==j-1 || k==j ) && j!=words.size()) k=i;
        }
        string line="";
        for(int k=i;k<j;k++) {
          line+=words[k];
        }
        out.push_back(line);
      }
    
      
      return out;
    }
};