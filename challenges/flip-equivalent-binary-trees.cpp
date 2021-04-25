// https://leetcode.com/problems/flip-equivalent-binary-trees

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
      if(!root1 && !root2) return true;
      return checkIfFlip(root1, root2);
    }
  
    bool checkIfFlip(TreeNode* root1, TreeNode* root2) {
      if(root1 && root2 && root1->val == root2->val) {
        int leftroot1 = root1->left? root1->left->val:-1;
        int rightroot1 = root1->right? root1->right->val:-1;
        int leftroot2 = root2->left? root2->left->val:-1;
        int rightroot2 = root2->right? root2->right->val:-1;
        bool a=true, b=true, c=true, d=true;
        if(leftroot1!=-1)
        if(leftroot1 == leftroot2) {
          a = checkIfFlip(root1->left, root2->left);
        } else if(leftroot1 == rightroot2) {
          c = checkIfFlip(root1->left, root2->right);
        } else {
          return false;
        }
        if(rightroot1!=-1)
        if(rightroot1 == rightroot2) {
          b = checkIfFlip(root1->right, root2->right);
        } else if(leftroot2 == rightroot1 ) {
          d = checkIfFlip(root1->right, root2->left);
        } else {
          return false;
        }
        return a && b && c && d;
      } else {
        return false;
      }
    }
};