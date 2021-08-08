// https://leetcode.com/problems/remove-duplicates-from-sorted-list

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
 /*
  Logic - SF. Note use of prev here
  Code - Stack
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      if(head ==NULL || head->next==NULL) return head;
      ListNode*  prev = head, *top=head;
      head=head->next;
      while(head) {
        if(head->val==prev->val) {
          prev->next=head->next;
        } else {
          prev=head;
        }
        head=head->next;         
      }
      
      return top;
    }
};