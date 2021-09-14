// https://leetcode.com/problems/design-log-storage-system/

// Note the use of multi map

class LogSystem {
private:
    multimap<string, int> log;
    string low = "2000:00:00:00:00:00";
    string high = "2017:12:31:23:59:59";
    unordered_map<string, int> map = {{"Year", 4}, {"Month", 7}, {"Day", 10},
                                      {"Hour", 13}, {"Minute", 16}, {"Second", 19}};

public:
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        log.emplace(timestamp, id);
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        int len = map[gra];
        s = s.substr(0, len) + low.substr(len);
        e = e.substr(0, len) + high.substr(len);
        auto first = log.lower_bound(s);
        auto last = log.upper_bound(e);
        vector<int> result;
        for (auto it = first; it != last; it++)
            result.push_back(it->second);
        return result;
    }
};