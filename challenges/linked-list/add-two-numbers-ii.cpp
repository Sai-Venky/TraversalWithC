// https://leetcode.com/problems/add-two-numbers-ii

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
    int carry, len1, len2;
    void addNumbers(ListNode* l1, ListNode* l2, ListNode* l3) {
      int sum=0;
      if(len1>len2) {
        l3->next = new ListNode;
        len1--;
        addNumbers(l1->next, l2, l3->next);
        sum+= l1->val + carry;
      } else if(len2>len1) {
        len2--;
        l3->next = new ListNode;
        addNumbers(l1, l2->next, l3->next);
        sum+= l2->val + carry;
      } else {
        len1--;
        len2--;
        if(len1!=0&&len2!=0) {
          l3->next = new ListNode;
          addNumbers(l1->next, l2->next, l3->next);
        }
        sum = l1->val + l2->val + carry;    
      }
      
      if(sum>9) {
        carry=1;
        sum=sum%10;
      } else {
        carry=0;
      }
      l3->val=sum; 
      
    }
  
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      carry=0;
      ListNode* l3 = NULL;
      len1=0, len2=0;
      l3=l1;
      while(l3) {
        len1++;l3=l3->next;
      }
      l3=l2;
      while(l3) {
        len2++;l3=l3->next;
      }
      l3=new ListNode;
      addNumbers(l1, l2, l3);
      if(carry) {
        ListNode* temp = new ListNode;  
        temp->val = carry;
        temp->next = l3;
        return temp;
      }
      return l3;
    }
};