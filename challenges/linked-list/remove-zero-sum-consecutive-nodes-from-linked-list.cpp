// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  
    ListNode* removeZeroSumSublists(ListNode* head) {
    unordered_map<int, ListNode*> m;
    ListNode* top=new ListNode(0);
    m[0]=top;
    top->next=head;
    int sum=0;
    while(head) {
      sum+=head->val;
      if(m.find(sum) != m.end()) {
        ListNode* start=m[sum];
        ListNode* prev=start;
        int psum=sum;
        while(prev!=head) {
          prev=prev->next;
          psum+=prev->val;
          if(prev!=head) m.erase(psum);
        }
        start->next=head->next;
      } else {
        m[sum]=head;
      }
      
      head=head->next;
    }
    return top->next;
    }
};