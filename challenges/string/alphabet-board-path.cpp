// https://leetcode.com/problems/alphabet-board-path

// Note the use L coming bwfore D and U brefore R. this is for the z alphabet traversal. Imp Edge case.

class Solution {
public:
    string alphabetBoardPath(string target) {
      string out="";
      pair<int, int> cur={0, 0};
      
      for(char c:target) {
        
        int lx=((c-'a')/5)-cur.first;
        int ly=((c-'a')%5)-cur.second;
        
        cur={(c-'a')/5, (c-'a')%5};
        if(ly<0) while(ly<0) out.push_back('L'), ly+=1;
        if(lx>0) while(lx>0) out.push_back('D'), lx-=1;
        if(lx<0) while(lx<0) out.push_back('U'), lx+=1;
        if(ly>0) while(ly>0) out.push_back('R'), ly-=1;

        out.push_back('!');
      }
      
      return out;
    }
};
