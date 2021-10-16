// https://leetcode.com/problems/game-of-life/

// Note the followup https://leetcode.com/problems/game-of-life/discuss/994037/Python-2-follow-up-questions%3A-O(1)-space-and-Infinite-board-Clean-and-Concise
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
      int m=board.size(), n=board[0].size();
      
      vector<vector<int>> dirs={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,1},{1,0}};
      
      for(int i=0;i<m;i++) {
       for(int j=0;j<n;j++) {
         int ct=0;
         for(auto dir:dirs) {
            int xi = i+dir[0];
            int yi = j+dir[1];
            if(xi<0 || yi<0 || xi>=m || yi>=n) continue;
            if(board[xi][yi]>=1) ct++;
         }
         if(board[i][j]==1 && (ct<2 || ct>3) ) {
           board[i][j]=2;
         } else if(board[i][j]==0 && (ct==3) ){
           board[i][j]=-1;
         }
       } 
      }
      
      for(int i=0;i<m;i++) {
       for(int j=0;j<n;j++) {
         if(board[i][j] == -1) board[i][j]=1;
         else if(board[i][j] == 2) board[i][j]=0;
       }
      }
      
    }
};


/*


2 - this is a 1 which is dead
1 - this is a 1 which can live
3 - this is a 0 which got new life
*/