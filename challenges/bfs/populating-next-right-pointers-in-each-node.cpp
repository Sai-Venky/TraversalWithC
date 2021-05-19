// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return {};
        vector<vector<Node*>> zigzagLevelOrderOutput;
   
        queue<Node*> levelQueue;
        levelQueue.push(root);  
        int level = 0;
        
        while (!levelQueue.empty()) {
            
            int levelQueueSize = levelQueue.size();  
            vector<Node*> curr(levelQueueSize); 
            
            for (int i = 0; i < levelQueueSize; i++) {
                Node* levelQueueNode = levelQueue.front();
                levelQueue.pop();
                curr[i] = levelQueueNode;                
                if (levelQueueNode->left) levelQueue.push(levelQueueNode->left);
                if (levelQueueNode->right) levelQueue.push(levelQueueNode->right);
            }
            zigzagLevelOrderOutput.push_back(curr);
            level++; 
        }
        
      Node *temp = NULL;
      for(int i=0; i<zigzagLevelOrderOutput.size(); i++) {
        temp = NULL;
        for(int j=zigzagLevelOrderOutput[i].size()-1; j>=0; j--) {
          cout<<zigzagLevelOrderOutput[i][j]->val;
          Node* cur = zigzagLevelOrderOutput[i][j];
          cur->next = temp;
          temp = cur;
        }
      }
      return root;
    }
};