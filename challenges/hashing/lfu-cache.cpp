// https://leetcode.com/problems/lfu-cache

// Note the use of double linked lists to store and use of minfreq here
class LFUCache {
public:
    int cap;
    int minFeq;
    unordered_map<int, int> mp;
    unordered_map<int, pair<int, list<int>::iterator>> key_iter;
    unordered_map<int, list<int>> freq_iter;
  
    LFUCache(int capacity) {cap=capacity;minFeq=0;}
    
    int get(int key) {
      if(mp.find(key) == mp.end()) return -1;
      update(key);
      return mp[key];
    }
    
    void put(int key, int value) {
      if(cap==0) return;
      
      if(mp.find(key) == mp.end()) {
        if(mp.size()==cap) evict();
        minFeq=1;
        freq_iter[minFeq].push_front(key);
        key_iter[key] = {minFeq, freq_iter[minFeq].begin()};
      } else {
        update(key);
      }
      mp[key] = value;
    }
  
    void evict() {
      key_iter.erase(freq_iter[minFeq].back());
      mp.erase(freq_iter[minFeq].back());
      freq_iter[minFeq].pop_back();
    }
  
    void update(int key) {
      pair<int, list<int>::iterator> p = key_iter[key];
      freq_iter[p.first].erase(p.second);
      if(freq_iter[p.first].size()==0 && p.first==minFeq) {
        minFeq=p.first+1;
      }
      freq_iter[p.first+1].push_front(key);
      key_iter[key] = {p.first+1, freq_iter[p.first+1].begin()};
    }
  
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */