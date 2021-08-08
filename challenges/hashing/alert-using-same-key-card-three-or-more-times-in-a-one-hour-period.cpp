// https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period

/*
    Note the use of hashing first and then sorting 
*/
class Solution {
public:
    vector<string> alertNames(vector<string>& names, vector<string>& times) {
        unordered_map<string, vector<int>> log;
        vector<string> res;
        for (int i = 0; i < names.size(); ++i)
            log[names[i]].push_back(stoi(times[i].substr(0, 2)) * 60 + stoi(times[i].substr(3)));
        for (auto &p : log) {
            sort(begin(p.second), end(p.second));
            for (int i = 0, j = 0; i < p.second.size(); ++i) {
                while(p.second[i] - p.second[j] > 60)
                    ++j;
                if (i - j >= 2) {
                    res.push_back(p.first);
                    break;
                }
            }
        }
        sort(begin(res), end(res));
        return res;
    }
};
