// https://leetcode.com/problems/rotate-list/


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
    ListNode* rotateRight(ListNode* head, int k) {
      if(head==NULL) return head;
      ListNode* tail = head;
      ListNode* prev;
      ListNode* newtail = head;
      ListNode* temp = head;
      int ct=0;
      while(tail) {
        ct++;
        prev=tail;
        tail=tail->next;
      }
      cout<<ct;
      if(k>=ct) {
        k=k%ct;      
      }
      ct=ct-k;
      cout<<ct;
      while(--ct) {
        newtail = newtail->next;
      }
      prev->next=head;
      head = newtail->next;
      newtail->next=NULL;
      return head;
    }
};