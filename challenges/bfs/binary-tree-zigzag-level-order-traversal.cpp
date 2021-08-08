// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

/*  
  Logic - BFS
  Code  - SF.
*/

class Solution {
public:
    
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> zigzagLevelOrderOutput;
   
        queue<TreeNode*> levelQueue;
        levelQueue.push(root);  
      
        int level = 0;
        
        while (!levelQueue.empty()) {
            
            int levelQueueSize = levelQueue.size();  
            vector<int> curr(levelQueueSize); 
            
            for (int i = 0; i < levelQueueSize; i++) {
                
                TreeNode* levelQueueNode = levelQueue.front();
                levelQueue.pop();
                
                if (level %2 == 0) {
                    curr[i] = levelQueueNode->val;
                } else {
                    curr[levelQueueSize - i - 1] = levelQueueNode->val; 
                }
                
                if (levelQueueNode->left) levelQueue.push(levelQueueNode->left);
                if (levelQueueNode->right) levelQueue.push(levelQueueNode->right);
            }
            zigzagLevelOrderOutput.push_back(curr);
            level++; 
        }
        return zigzagLevelOrderOutput;
  }
};