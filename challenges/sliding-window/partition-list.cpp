// https://leetcode.com/problems/partition-list/

/*  
    Code - Two pointers
    Logic - SF
*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
      ListNode* low_t = new ListNode(0);
      ListNode* high_t= new ListNode(0);
      ListNode* low=low_t, *high=high_t;
      while(head) {
        ListNode* &ref = head->val>= x ? high : low;
        ref->next=head;
        ref=ref->next;
        head=head->next;
      }
      low->next=high_t->next;
      high->next=NULL;
      return low_t->next;
    }
};