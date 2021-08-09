// https://leetcode.com/problems/merge-k-sorted-lists

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

 // Note the use of first elements alone similar to kth-smallest-element-in-a-sorted-matrix
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
      
      priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> q;      
      
      int n=lists.size();
      for(int i=0;i<n;i++) {
        if(lists[i]!=NULL) q.push({lists[i]->val, lists[i]});
      }
      
      ListNode* tail=NULL;
      if(q.empty()) return tail;
      
      while(!q.empty()) {
        pair<int, ListNode*> p=q.top();
        q.pop();
        if(p.second->next!=NULL) q.push(make_pair(p.second->next->val, p.second->next));
        p.second->next= tail;
        tail=p.second;
      }
      ListNode* head=NULL;
      ListNode* bck=NULL;
      
      while(tail!=NULL) {
        head = tail->next;
        tail->next = bck;
        bck=tail;
        tail=head;
      }
      
      return bck;
    }
};