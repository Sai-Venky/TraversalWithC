// https://leetcode.com/problems/battleships-in-a-board/

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
      int ct=0;
      int m= board.size(), n=board[0].size();
      for(int i=0;i<m;i++) {  
        for(int j=0;j<n;j++) {
          if(board[i][j]=='X') {
            bool check=true;
            if(i+1<m && board[i+1][j] == 'X') check=false;
            if(j+1<n && board[i][j+1] == 'X') check=false;
            ct = check==true?ct+1:ct;
          }
        }       
      }
      return ct;
    }
};