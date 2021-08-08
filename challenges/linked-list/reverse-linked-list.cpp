// https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head) {
        
      if(head==NULL) return head;
      ListNode *cur=head;
      ListNode *bck=NULL;
      ListNode *fwd=NULL;
      while(cur!=NULL){
        fwd = cur->next;
        cur->next=bck;
        bck=cur;
        cur=fwd;
      }
      return bck;
      
    }
};