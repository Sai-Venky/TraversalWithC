// https://leetcode.com/problems/palindrome-linked-list/

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
    ListNode* tail;
    bool pal = true;
    void checkIfPalindrone(ListNode* head) {
      if(head == NULL) return;
      checkIfPalindrone(head->next);
      if(pal) {
        pal = head->val == tail->val;
        tail = tail->next;
      }
    }
  
    bool isPalindrome(ListNode* head) {
      tail = head;
      checkIfPalindrone(head);
      return pal;
    }
};
