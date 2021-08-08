// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
  Logic - SF. 2 Pointers Approach. Cover edge cases
  Code - Stack
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        struct ListNode* front = head;
        struct ListNode* behind = head;

        while (front != NULL) {
            front = front->next;

            if (n-- < 0) behind = behind->next;
        }
        if (n == 0) head = head->next;
        else behind->next = behind->next->next;
        return head;
    }
};