// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal

class Solution {
    TreeNode* recoverFromPreorder(string &S, int &i, int d)
    {
        int j = S.find_first_of("0123456789", i); 
        if(j - i != d) return NULL;
        
        i = S.find("-", j); // https://www.geeksforgeeks.org/string-find-in-cpp/
        int val = stoi(S.substr(j, i - j));
        
        TreeNode* root=new TreeNode(val);
        root->left = recoverFromPreorder(S, i, d + 1);
        root->right = recoverFromPreorder(S, i, d + 1);
        return root;
    }
public:
    TreeNode* recoverFromPreorder(string S)
    {
        int i = 0;
        return recoverFromPreorder(S, i, 0);
    }
};

class Solution {
public:
    int s=0;
    TreeNode* recoverTree(string T, int D) {
      if(s==T.length()) {return NULL;}
      
      int no=0, i=s, curD=0;
      while(i<T.length() && T[i]=='-') curD++, i++;

      if(curD<D) {return NULL;}
      
      while(i<T.length() && T[i]!='-') no=no*10 + (T[i++]-'0');      
      s=i;
     
      TreeNode* root=new TreeNode(no);
      root->left  = recoverTree(T, D+1);
      root->right = recoverTree(T, D+1);
       
      return root;
    }
  
    TreeNode* recoverFromPreorder(string T) {
      return recoverTree(T, 0);
    }
};