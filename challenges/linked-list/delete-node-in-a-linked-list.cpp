// https://leetcode.com/problems/delete-node-in-a-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
  Logic - SF
  Code - Stack
*/

class Solution {
public:
    void deleteNode(ListNode* node) {
        
       if(node!=NULL) {
           node->val = node->next->val;
           node->next = node->next->next;
       }
        
    }
};