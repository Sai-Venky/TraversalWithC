// https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode;
        ListNode* temp = l3;
        int carry = 0;
        while(l1!=NULL && l2!=NULL) {
            temp->next = new ListNode;
            temp = temp->next;
            int sum = l1->val + l2->val + carry;
            carry = 0;
            if(sum >=10) {
                sum = sum % 10;
                carry = 1;
            }
            temp->val = sum;

            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1!=NULL) {
            temp->next = new ListNode;
            temp = temp->next;
            int sum = l1->val + carry;
            carry = 0;
            if(sum >=10) {
                sum = sum % 10;
                carry = 1;
            }
            temp->val = sum;
            l1 = l1->next;
        }
        
        while(l2!=NULL) {
            temp->next = new ListNode;
            temp = temp->next;
            int sum = l2->val + carry;
            carry = 0;
            if(sum >=10) {
                sum = sum % 10;
                carry = 1;
            }
            temp->val = sum;
            l2 = l2->next;
        }
        if(carry ==1){
            temp->next = new ListNode;
            temp = temp->next;  
            temp->val = carry;
        }
        
        
        return l3->next;
        
    }
};