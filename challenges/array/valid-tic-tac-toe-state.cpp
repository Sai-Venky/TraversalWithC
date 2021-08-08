// https://leetcode.com/problems/valid-tic-tac-toe-state

/*
    The logic is for x to have extra count when it wins and o to have equal count when it wins
    Consider the edge case
    ["XXX","OOX","OOX"]
*/

class Solution {
public:
    bool iswin(vector<string> &board, char c) {
        return ((board[0][0] == c && board[0][1] == c && board[0][2] == c) ||
          (board[1][0] == c && board[1][1] == c && board[1][2] == c) ||
          (board[2][0] == c && board[2][1] == c && board[2][2] == c) ||
          (board[0][0] == c && board[1][0] == c && board[2][0] == c) ||
          (board[0][1] == c && board[1][1] == c && board[2][1] == c) ||
          (board[0][2] == c && board[1][2] == c && board[2][2] == c) ||
          (board[0][0] == c && board[1][1] == c && board[2][2] == c) ||
          (board[0][2] == c && board[1][1] == c && board[2][0] == c));
    }
    bool validTicTacToe(vector<string>& board) {
        int xcnt = 0, ocnt = 0;
        for(string s: board) {
            for(char c: s) {
                if(c == 'X') xcnt++;
                else if(c == 'O') ocnt++;
            }
        }
        if(xcnt != ocnt && xcnt != ocnt + 1) return false;          // X can have equal or only 1 more move than O
        if(iswin(board, 'X') && xcnt != ocnt + 1) return false;     // X will win by having one additional move
        if(iswin(board, 'O') && xcnt != ocnt) return false;         // since X played first, O can win only when both have made same number of moves
        return true;
    }
};