// https://leetcode.com/problems/bulb-switcher-iv

class Solution {
public:
     int minFlips(string s) {
        if(s.size()==0)return 0;
        int c=0;
        if(s[0]=='1')c++;
        for(int i=1;i<s.size();i++){
            if(s[i]!=s[i-1])c++;
        }
        return c;
    }
};