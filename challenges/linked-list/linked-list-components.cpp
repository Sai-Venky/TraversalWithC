// https://leetcode.com/problems/linked-list-components/

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
  Logic - SF. Note the use of  !subset.count(head->next->val)
  Code - Stack
 */

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> subset;
        int connected_components = 0;
        
        for(auto n : G)
            subset.insert(n);
        
        while(head) {
            if (subset.count(head->val) && (head->next == NULL || !subset.count(head->next->val)))
                connected_components++;
            head = head->next;
        }   
        return connected_components;
    }
};