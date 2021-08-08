// https://leetcode.com/problems/swap-nodes-in-pairs

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
  Logic - SF. Note use of recursion here
  Code - Stack
*/
class Solution {
public:
    ListNode* swap(ListNode* first, ListNode* second) {  
      if(second && first) { 
        ListNode* third = second->next;
        ListNode* fourth = NULL;
        second->next=first;
        fourth = third?third->next:fourth;
        first->next = swap(third, fourth);
      } else {
        return first;
      }

      return second;
    }
  
    ListNode* swapPairs(ListNode* head) {
      if(!head || !head->next) return head;
      ListNode* first=head;
      ListNode* second=head->next;
      
      return swap(first, second);
    }
};