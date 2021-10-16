// https://leetcode.com/problems/remove-comments

class Solution {
public:
    vector<string> removeComments(vector<string>& a) {
        vector<string> ret;
        string build;
        bool block = false;
        
        for(string line : a){
            for(int i = 0, m = line.size(); i < m; i++){
                string two = line.substr(i, 2);
                if(!block){
                    if(two == "//") break;
                    else if(two == "/*") block = true, i++;
                    else build.push_back(line[i]);
                } else if(two == "*/") block = false, i++;
            }
            if(!block && build.size()) ret.push_back(build), build.clear();
        }
        
        return ret;
    }
};