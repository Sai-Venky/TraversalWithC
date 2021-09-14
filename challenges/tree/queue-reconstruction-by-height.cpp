// https://leetcode.com/problems/queue-reconstruction-by-height/

// Note the use of compare and then segment tree approach
/*
  class Solution {
  public:
      static bool compare(vector<int> &s1, vector<int> &s2) {
          if(s1[1] == s2[1]) return s1[0]>s2[0];
          return s1[1]<s2[1];
      }
    
      vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> out;
        sort(people.begin(), people.end(), compare);
        
        for(int i=0;i<people.size();i++) {
          int no=people[i][0], ct=people[i][1], j=0;
          for(j=0;j<out.size();j++) {
            if(ct==0) break;
            else if(out[j][0]>=no) ct--;
          }
          out.insert(out.begin()+j, people[i]);
        }
        return out;
      }
  };

  */

class Node {
    public:
      int val=1;
      Node *left=NULL;
      Node *right=NULL;
      int low, high;
  
      Node(int l, int h) {
        low=l; high=h;
      }
};

class Solution {
public:
    
    Node* buildTree(int l, int h) {
      Node* root=new Node(l, h);
      if(l==h) {
        return root;
      }
      int m=l+(h-l)/2;
      root->left = buildTree(l, m);
      root->right = buildTree(m+1, h);
      root->val = root->left->val + root->right->val;
      return root;
    }
    
    int query(Node* root, int slot) {
      int out;
      if(root->low == root->high) {
        root->val = 0;
        return root->low;
      }
      
      if(root->left->val>=slot) {
        out = query(root->left, slot);
      } else {
        out = query(root->right, slot-root->left->val);
      }
      
      root->val = root->left->val + root->right->val;
      return out;
    }
  
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<vector<int>> res(n);
        Node* root = buildTree(0, n-1);
        
        sort(people.begin(), people.end(), [&](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            } else {
                return a[0] < b[0];
            }
        });
        
        for (int i = 0; i < people.size(); i++) {
            int id = query(root, people[i][1]+1);
            res[id] = people[i];
        }
        
        return res;
    }
};