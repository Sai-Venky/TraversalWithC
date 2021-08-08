// https://leetcode.com/problems/kth-largest-element-in-a-stream
/*
  Code  - SF
  Logic - Heap
*/
class KthLargest {
  int k_;
  priority_queue<int, vector<int>, greater<int>> q;
public:
    KthLargest(int k, vector<int>& nums) {
      k_=k;
      for(int num:nums) {
        q.push(num);
      }
    }
    
    int add(int val) {
      q.push(val);
      while(q.size()>k_) {
        q.pop();
      }
      return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */