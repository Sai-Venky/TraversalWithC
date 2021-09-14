// https://leetcode.com/problems/time-based-key-value-store/

class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, vector<pair<int, string>>> mp;
  
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
      mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
      int l=0, h=mp[key].size()-1;
      string value="";
      while(l<=h) {
        int m=l+(h-l)/2;
        if(mp[key][m].first>timestamp) {
          h=m-1;
        } else {
          value=mp[key][m].second;
          l=m+1;
        }
      }
      return value;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */