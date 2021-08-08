// https://leetcode.com/problems/merge-two-sorted-lists

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
  Logic - SF
  Code - Stack
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode *l3= new ListNode;
      ListNode *head=l3;
      while(l1!=NULL && l2!=NULL) {
        ListNode *temp = new ListNode;
        if(l1->val>l2->val) {
          temp->val = l2->val;
          l2 = l2->next;
        } else {
          temp->val = l1->val;
          l1 = l1->next;
        }
        l3->next = temp;
        l3 = temp;
      }
      while(l1!=NULL) {
        ListNode *temp = new ListNode;
        temp->val = l1->val;
        l1 = l1->next;
        l3->next = temp;
        l3 = temp;
      }
      while(l2!=NULL) {
        ListNode *temp = new ListNode;
        temp->val = l2->val;
        l2 = l2->next;
        l3->next = temp;
        l3 = temp;
      }      
      return head->next;
    }
};