// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/*  
  Logic - BFS
  Code  - SF.
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
      queue<Node*> q;
      vector<vector<int>> outputs;
      if(root==NULL) return outputs;
      q.push(root);
      
      while(!q.empty()) {
        vector<int> output;
        int size=q.size();
        for(int i=0;i<size;i++) {
          Node* node = q.front();
          
          for(auto n:node->children) {
            q.push(n);
          }
          output.push_back(node->val);
          q.pop();
          
        }
        outputs.push_back(output);
      }
      return outputs;
    }
};