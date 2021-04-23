// https://leetcode.com/problems/all-possible-full-binary-trees

class Solution {
public:
    unordered_map<int, vector<TreeNode*>> umap;  
  
    vector<TreeNode*> allPossibleFBT(int N) {
      vector<TreeNode*> output;
      if(N%2==0) return output;
      if(umap.find(N)!=umap.end()) return umap[N];
      if(N==1) {
        TreeNode* node = new TreeNode(0);
        output.push_back(node); 
        umap[N] = output;
        return output;
      }
      
      for(int i=2;i<N;i+=2) {
        
        for(auto l: allPossibleFBT(i-1)) {
          for(auto r: allPossibleFBT(N-i)) {
            TreeNode* node = new TreeNode(0);
            node->left = l;
            node->right = r;
            output.push_back(node);
          }
        }
      }
      umap[N] = output;
      return output;
    }
};