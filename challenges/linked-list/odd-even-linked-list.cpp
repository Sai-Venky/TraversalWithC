// https://leetcode.com/problems/odd-even-linked-list

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
  Logic - SF. Note use of single O(1) space 
  Code - Stack
*/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return head;
        }
        ListNode* odd = head, *even = head->next, *temp=head->next->next;
        ListNode* evenhead = even;
        int i=0;
        while(temp!=NULL) {
            if(i%2==0) {
               odd->next = temp; 
                odd = temp;
            } else {
               even->next = temp;
                even = temp;
            }
            temp = temp->next;
            i++;
        }
        even->next = NULL;
        odd->next = evenhead;
        return head;
    
    }
};