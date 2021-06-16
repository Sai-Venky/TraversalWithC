// https://leetcode.com/problems/next-greater-node-in-linked-list/

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
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
      int i=0;
      stack<pair<int,int>> s;
      ListNode* trav=head;
      while(trav && ++i) trav=trav->next;
      
      vector<int> out(i, 0); i=0;
      while(head) {
        while(!s.empty() && s.top().first < head->val) {
          out[s.top().second] = head->val; s.pop();
        }
        s.push({head->val, i++});
        head=head->next;
      }
      
      return out;
    }
};