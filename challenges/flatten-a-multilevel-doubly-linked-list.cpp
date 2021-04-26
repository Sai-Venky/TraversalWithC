// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* par;
    Node* flatten(Node* head) {
      if(head==NULL) return head;
      par = NULL;
      flattenDLL(head);
      return head;
    }
  
    void flattenDLL(Node* head) {
      Node* r = head->next;
      Node* c = head->child;
      if(par) {
        par->child=NULL;   
        par->next=head;
        head->prev = par;
      }
      par = head;
      if(c)
      flattenDLL(c);
      if(r)
      flattenDLL(r);
    }
};

/*

Node* flatten(Node* head) {
	for (Node* h = head; h; h = h->next)
	{
		if (h->child)
		{
			Node* next = h->next;
			h->next = h->child;
			h->next->prev = h;
			h->child = NULL;
			Node* p = h->next;
			while (p->next) p = p->next;
			p->next = next;
			if (next) next->prev = p;
		}
	}
	return head;
}

/*