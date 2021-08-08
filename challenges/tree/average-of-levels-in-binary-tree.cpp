// https://leetcode.com/problems/average-of-levels-in-binary-tree/

/**
 SF
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
      vector<double> out;
      
      queue<TreeNode*> q;
      q.push(root);
      
      while(!q.empty()) {
        int n=q.size();
        double avg=0;
        for(int i=0;i<n;i++) {
          TreeNode* node=q.front();
          q.pop();
          avg+=node->val;
          if(node->left) {
            q.push(node->left);
          }
          if(node->right) {
            q.push(node->right);
          }
          
        }
        if(n>0) avg=avg/n;
        out.push_back(avg);
      }
      
      return out;
    }
};

