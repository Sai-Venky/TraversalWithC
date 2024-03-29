// https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations

/*
    Code  - SF. Note use of two queues. Identify that we need to take fastest watys to update array .
    NOte the part where we stop when diff not greater than as we can adjust that last value as 2,3,4,5,6 accordingly
    Logic - Heap
    Time: O(n log n + m log m), where n and m are sizes of our arrays.
    Memory: O(n + m) for the first solution, and O(1) - for the second (we re-use the original arrays as heaps).
    
    int minOperations(vector<int>& n1, vector<int>& n2) {
        if (n2.size() * 6 < n1.size() || n1.size() * 6 < n2.size())
            return -1;
        int sum1 = accumulate(begin(n1), end(n1), 0), sum2 = accumulate(begin(n2), end(n2), 0);
        if (sum1 > sum2)
            swap(n1, n2);
        priority_queue <int, vector<int>, greater<int>> q1(begin(n1), end(n1));
        priority_queue<int> q2(begin(n2), end(n2));
        int cnt = 0, diff = abs(sum1 - sum2);
        while (diff > 0) {
            ++cnt;
            if (q1.empty() || (!q2.empty() && q2.top() - 1 > 6 - q1.top())) {
                diff -= q2.top() - 1;
                q2.pop();
            } else {
                diff -= 6 - q1.top();
                q1.pop();
            }
        }
        return cnt;
    }
*/
class Solution {
public:
    int minOperations(vector<int>& n1, vector<int>& n2) {
        if (n2.size() * 6 < n1.size() || n1.size() * 6 < n2.size())
            return -1;
        int sum1 = accumulate(begin(n1), end(n1), 0), sum2 = accumulate(begin(n2), end(n2), 0);
        if (sum1 > sum2)
            swap(n1, n2);
        make_heap(begin(n1), end(n1), greater<int>());
        make_heap(begin(n2), end(n2));
        int cnt = 0, diff = abs(sum1 - sum2);
        while (diff > 0) {
            ++cnt;
            if (n1.empty() || (!n2.empty() && n2.front() - 1 > 6 - n1.front())) {
                diff -= n2.front() - 1;
                pop_heap(begin(n2), end(n2)); n2.pop_back();
            } else {
                diff -= 6 - n1.front();
                pop_heap(begin(n1), end(n1), greater<int>()); n1.pop_back();            
            }
        }
        return cnt;
    }
};