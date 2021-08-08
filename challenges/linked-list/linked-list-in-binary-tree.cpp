// https://leetcode.com/problems/linked-list-in-binary-tree

/*
  Logic - SF. Note the use of checking at every position with recursive function
  Code - Stack
  Time complexity:
It's O(N*max(L, H))
where L = length of lined list
and H = height of the tree
The reason is for every node of BT, we have to check if the linked list can be found from that node. And in worst case either we exhaust the height or we exhaust the linked list. And Remember we have to do this for each node of BT (and worst case would be the linked list is not the part of the BT).
*/

class Solution {
public:
    bool findSubPath(ListNode* head, TreeNode* root) {
        if (!head) return true;
        if (!root) return false;
        return head->val == root->val && (findSubPath(head->next, root->left) || findSubPath(head->next, root->right));
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        return findSubPath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};