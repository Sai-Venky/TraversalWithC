// https://leetcode.com/problems/maximum-frequency-stack/

/*  
  Logic - Note the use of map to store frequency and keeping track of max frequency
  Code  - Stack
*/

class FreqStack {
public:
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> m;
    int maxf=0;
    
    void push(int val) {
      maxf=max(maxf, ++freq[val]);
      m[freq[val]].push(val);
    }
    
    int pop() {
      int val=m[maxf].top();
      m[maxf].pop();
      if (!m[freq[val]--].size()) maxf--;
      return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */