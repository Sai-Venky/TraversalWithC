// https://leetcode.com/problems/longest-consecutive-sequence/

/*

neither i+1 nor i-1 has been seen: m[i]=1;

both i+1 and i-1 have been seen: extend m[i+m[i+1]] and m[i-m[i-1]] to each other;

only i+1 has been seen: extend m[i+m[i+1]] and m[i] to each other;

only i-1 has been seen: extend m[i-m[i-1]] and m[i] to each other.

int longestConsecutive(vector<int> &num) {
    unordered_map<int, int> m;
    int r = 0;
    for (int i : num) {
        if (m[i]) continue;
        r = max(r, m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1);
    }
    return r;
}

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> record(num.begin(),num.end());
        int res = 1;
        for(int n : num){
            if(record.find(n)==record.end()) continue;
            record.erase(n);
            int prev = n-1,next = n+1;
            while(record.find(prev)!=record.end()) record.erase(prev--);
            while(record.find(next)!=record.end()) record.erase(next++);
            res = max(res,next-prev-1);
        }
        return res;
    }
};
*/

class Solution {
public:
    int find(vector<int> &parent, int x)  {
      if(parent[x]==x) return x;
      parent[x]=find(parent, parent[x]);
      return parent[x];
    }
    
    void uni(vector<int> &parent, int x, int y) {
      int u=find(parent, x);
      int v=find(parent, y);
      if(u!=v)
        parent[u]=v;
    }
  
    int longestConsecutive(vector<int>& nums) {
      unordered_map<int, int> m;
      unordered_map<int, int> ct;
      int out=0, n=nums.size();
      
      vector<int> parent(n, -1);
      for(int i=0;i<n;i++) parent[i]=i;
      for(int i=0;i<n;i++) {
        if(m.find(nums[i])!=m.end()) continue;
        m[nums[i]]=i;
        if(m.find(nums[i]-1)!=m.end()) {
          uni(parent, i, m[nums[i]-1]);
        }
        if(m.find(nums[i]+1)!=m.end()) {
          uni(parent, i, m[nums[i]+1]);
        }
      }
      
      for(int v:parent) {
        ct[find(parent, v)]++;
      }
      for(auto v:ct) {
        out=max(out, v.second);
      }
      
      return out;
    }
};
