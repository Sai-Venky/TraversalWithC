// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii

/*  
  Logic - BFS
  Code  - Traversing from right to left in the assignment.
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