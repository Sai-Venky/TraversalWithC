// https://leetcode.com/problems/middle-of-the-linked-list

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
    ListNode* middleNode(ListNode* head) {
      ListNode* slow=head; 
      ListNode* fast=head; 
      while(fast && fast->next) {
        fast=fast->next;
        slow=slow->next;
        if(fast) {
          fast=fast->next;       
        }
      }
      return slow;
    }
};