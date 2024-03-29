// https://leetcode.com/problems/intersection-of-two-linked-lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /*
  Logic - SF. Note the use of reverting to start in case of end
  Code - Stack
 */
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *cur1 = headA, *cur2 = headB;
    while(cur1 != cur2){
        cur1 = cur1?cur1->next:headB;
        cur2 = cur2?cur2->next:headA;
    }
    return cur1;
}
};

 /*
  Logic - SF. Note the use of pointers and diff traversal to correctly go the node
  Code - Stack
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *travA = headA;
        ListNode *travB = headB;
        int ct1=0, ct2=0, diff;
        while(travA!=NULL) {
            ct1++;
            travA = travA->next;
        }

        while(travB!=NULL) {
            ct2++;
            travB = travB->next;
        }
        if(ct1-ct2>0) {
            diff = ct1-ct2;
            while(diff>0) {
                diff--;
                headA = headA->next;
            }
        } else {
           diff = ct2-ct1;
            while(diff>0) {
                diff--;
                headB = headB->next;
            } 
        }
        while(headA!=NULL && headB!=NULL) {
            if(headA == headB) {break;}
                headA = headA->next;
                headB = headB->next;
        }
        return headA;
        
    }
};