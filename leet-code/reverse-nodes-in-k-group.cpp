// https://leetcode.com/problems/reverse-nodes-in-k-group

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