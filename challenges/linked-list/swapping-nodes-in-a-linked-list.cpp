// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

/*
    
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *n1 = nullptr, *n2 = nullptr;
        for (auto p = head; p != nullptr; p = p->next) {
            n2 = n2 == nullptr ? nullptr : n2->next;
            if (--k == 0) {
                n1 = p;
                n2 = head;
            }
        }
        swap(n1->val, n2->val);
        return head;
    }
 */
 /*
  Logic - SF. Note the use of recursion here
  Code - Stack
*/
class Solution {
public:
    ListNode* tail;
    
    void traverse(ListNode* head, int &k) {
      if(head==NULL) {
        return;
      }
      
      traverse(head->next, k);
      if(k--==1) {
        swap(tail->val, head->val);
      }
      tail=tail->next;
    }
  
    ListNode* swapNodes(ListNode* head, int k) {
      tail=head;
      traverse(head, k);
      return head;
    }
};