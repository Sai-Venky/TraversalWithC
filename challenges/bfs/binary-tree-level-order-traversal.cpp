// https://leetcode.com/problems/binary-tree-level-order-traversal

/*  
  Logic - BFS
  Code  - SF.
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> levelOrderOutput;
   
        queue<TreeNode*> levelQueue;
        levelQueue.push(root);  
      
        int level = 0;
        
        while (!levelQueue.empty()) {
            
            int levelQueueSize = levelQueue.size();  
            vector<int> curr(levelQueueSize); 
            
            for (int i = 0; i < levelQueueSize; i++) {
                
                TreeNode* levelQueueNode = levelQueue.front();
                levelQueue.pop();
                
                curr[i] = levelQueueNode->val;
                
                if (levelQueueNode->left) levelQueue.push(levelQueueNode->left);
                if (levelQueueNode->right) levelQueue.push(levelQueueNode->right);
            }
            levelOrderOutput.push_back(curr);
            level++; 
        }
        return levelOrderOutput;
  }
};