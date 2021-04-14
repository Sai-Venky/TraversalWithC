// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
      queue<Node*> collection;
      if(root==NULL) return root;
      collection.push(root);
      root->next=NULL;
      while(!collection.empty()) {        
        Node* temp = NULL;
        int size=collection.size();
        for(int i=0;i<size;i++) {
          Node* trav = collection.front();
          collection.pop();
          
          if(trav->right) {
            trav->right->next=temp;
            collection.push(trav->right);
            temp=trav->right;
          }

          if(trav->left) {
            trav->left->next=temp;
            collection.push(trav->left);
            temp=trav->left;
          } 
        }

      
      }
      return root;
      
      
    }
};