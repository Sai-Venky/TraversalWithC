// https://leetcode.com/problems/sort-characters-by-frequency

/*
  Code  - SF
  Logic - Heap
*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        vector<string> bucket(s.size()+1, "");
        string res;
        
        //count frequency of each character
        for(char c:s) freq[c]++;
        //put character into frequency bucket
        for(auto& it:freq) {
            int n = it.second;
            char c = it.first;
            bucket[n].append(n, c);
        }
        //form descending sorted string
        for(int i=s.size(); i>0; i--) {
            if(!bucket[i].empty())
                res.append(bucket[i]);
        }
        return res;
    }
};

class Solution {
public:

    struct Frequency {
      bool operator()(const pair<char, int> &p1, const pair<char, int> &p2) {
        return p1.second < p2.second;
      }
    };
    priority_queue<pair<char, int>, vector<pair<char, int>>, Frequency> q;
  
    string frequencySort(string s) {
      string out="";
      map<char, int> mp;
      for(auto c:s) mp[c]++;
      
      for(auto val:mp)  {
        q.push({val.first, val.second});
      }
      
      while(!q.empty()) {
        pair<char, int> p = q.top();
        q.pop();
        while(p.second>0) {
          out+=p.first;
          p.second--;
        }
      }
      return out;
    }
};