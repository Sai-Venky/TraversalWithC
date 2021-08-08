// https://leetcode.com/problems/reverse-nodes-in-k-group

/*
  Logic - SF. Note careful use of pointers here.
  Code - Stack
*/
/*
    Recursive solution has O(n) space complexity because of call stacks.

	ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cursor = head;
        for(int i = 0; i < k; i++){
            if(cursor == nullptr) return head;
            cursor = cursor->next;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;
        for(int i = 0; i < k; i++){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }

    Iterative solution has O(1) space complexity.
    https://leetcode.com/problems/reverse-nodes-in-k-group/discuss/11457/20-line-iterative-C%2B%2B-solution     
    IMP - Note the use of batch by batch iterative replace
    class Solution {
    public:
        ListNode *reverseKGroup(ListNode *head, int k) {
            if(head==NULL||k==1) return head;
            int num=0;
            ListNode *preheader = new ListNode(-1);
            preheader->next = head;
            ListNode *cur = preheader, *nex, *pre = preheader;
            while(cur = cur->next) 
                num++;
            while(num>=k) {
                cur = pre->next;
                nex = cur->next;
                for(int i=1;i<k;++i) {
                    cur->next=nex->next;
                    nex->next=pre->next;
                    pre->next=nex;
                    nex=cur->next;
                }
                pre = cur;
                num-=k;
            }
            return preheader->next;
        }
    };

*/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *scoutStart = NULL, *scoutEnd = NULL, *cavalryStart = NULL, *cavalryEnd = NULL;
        ListNode  *nextLocation = NULL, *previousLocation = NULL, *scoutPtr = head, *cavalryPtr = head;
        int scoutTrack, cavalryTrack;
        bool proceed = true;
        
        while (proceed == true) {
            
            scoutTrack = 0;
            cavalryTrack = 0;
            previousLocation = NULL;
         
            while (scoutTrack < k) {

                if(scoutTrack == 0) scoutStart = scoutPtr;
                if(scoutTrack == k-1) scoutEnd = scoutPtr;
                if(scoutPtr == NULL) {
                    scoutEnd = scoutStart;
                    proceed = false;
                    break;
                };
                cout<<scoutPtr->val<<" ";

                scoutPtr = scoutPtr->next;
                
                scoutTrack ++;
            }
            
            if(cavalryStart!=NULL) {
                cavalryStart->next = scoutEnd;
            } else {
                head = scoutEnd;
            } 
            cavalryStart = scoutStart;
            cavalryEnd = scoutEnd;      
            
            if(proceed == false) {break;}
            
            while (cavalryTrack < k) {
                              
                nextLocation = cavalryPtr->next;
  
                if(previousLocation != NULL)
                cavalryPtr->next = previousLocation;
                    
                previousLocation = cavalryPtr;
                cavalryPtr = nextLocation;
                
                cavalryTrack++;
            }
            

        }
        
        return head;
    }
};