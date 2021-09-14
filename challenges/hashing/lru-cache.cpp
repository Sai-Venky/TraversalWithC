// https://leetcode.com/problems/lru-cache

/*
    Note the use of storing iterator to point to beginning element here.
    List has o(1) for deletion and see the use of begin() here instead of end() as begin points ot one element.
*/

class LRUCache {
public:
  unordered_map<int, list<int>::iterator> lru_tracker;
  unordered_map<int, int> keys;
    list<int> lru;
    int cap;
  
    LRUCache(int capacity) {
      cap=capacity;
    }
    
    int get(int key) {
      if(keys.find(key) == keys.end()) return -1;
      else lru.erase(lru_tracker[key]);
      
      lru.push_front(key);
      lru_tracker[key] = lru.begin();
      return keys[key];
    }
  
    
    void put(int key, int value) {
      if(keys.find(key) != keys.end()) lru.erase(lru_tracker[key]);
      lru.push_front(key);
      lru_tracker[key] = lru.begin();
      keys[key] = value;
      
      if(keys.size()>cap) {
        lru_tracker.erase(lru.back());
        keys.erase(lru.back());
        lru.pop_back();
      }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */