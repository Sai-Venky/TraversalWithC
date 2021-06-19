// https://leetcode.com/problems/sort-list

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
    ListNode* sortList(ListNode* head) {
      int count=0;
      ListNode* trav=head;
      ListNode *sub1=NULL, *sub2=NULL, *tail=NULL;
      while(trav!=NULL) {
        trav=trav->next;
        count++;
      }
      ListNode *dummy = new ListNode;
      dummy->next=head;
      for (int step=1; step<count; step*=2) {     
        tail = dummy;
        trav=tail->next;
        while(trav!=NULL) {

          for (int i = 0; i < 2; ++i) {
            if(i%2==0) {
              sub1 = trav;
            } else {
              sub2 = trav;
            }
            ListNode *proc = NULL; 
            for (int j = 0; j < step && NULL != trav; ++j, trav = trav->next) {
              proc = trav;
            }
            if (NULL != proc) {
              proc->next = NULL;
            }
          }
            
          if(sub2) {
            while(sub1 && sub2) {
              if(sub1->val>=sub2->val) {
                tail->next= sub2;
                sub2=sub2->next;
              } else {
                tail->next= sub1;
                sub1=sub1->next;
              }
              tail=tail->next;
            }
            while(sub1) {
              tail->next= sub1;
              sub1=sub1->next;  
              tail=tail->next;
            }
            while(sub2) {
              tail->next= sub2;
              sub2=sub2->next;  
              tail=tail->next;
            }
            tail->next=NULL;
          } else {
            tail->next=sub1;
          }
        }
      }
      return dummy->next;
    }
};