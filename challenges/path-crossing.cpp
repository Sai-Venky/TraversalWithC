// https://leetcode.com/problems/path-crossing

/*
    A Grid is created.
    For N,E x, y values added.
    For S,W x, y values subtracted.
    If overlapped then returned true
*/
class Solution {
public:
    bool isPathCrossing(string path) {
        
        set <pair<int, int>> s;
        int cur_x=0, cur_y=0;
        s.insert(make_pair(0, 0));
        for(int i=0; i<path.length(); i++) {
            if(path[i] == 'N') {
                cur_y++;
            } else if(path[i] == 'E') {
                cur_x++;
            } else if(path[i] == 'W') {
                cur_x--;
            } else if(path[i] == 'S') {
                cur_y--;
            }
            auto itr = s.insert(make_pair(cur_x, cur_y));
            if(!itr.second){
                return true;
            }
        }
        
        return false;
    }
};