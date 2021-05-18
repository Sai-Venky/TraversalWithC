// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes
// Refer LCA https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

class Solution {
public:
    TreeNode* lca( TreeNode* root, TreeNode* p, TreeNode* q ) {
        if ( !root || root == p || root == q ) return root;
        TreeNode *left = lca( root->left, p, q );
        TreeNode *right = lca (root->right, p, q );

        return !left? right: !right? left: root;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if ( !root || !root->left && !root->right ) return root;
        TreeNode *leftMost = NULL;
        TreeNode *rightMost = NULL;
        
        queue<TreeNode*> q;
        q.push(root);
        while( !q.empty() ) {
            int levelSize = q.size();
            for(int level = 0; level < levelSize; level++ ) {
                TreeNode* node = q.front(); q.pop();
                if ( level == 0 ) leftMost = node;
                if ( level == levelSize - 1 ) rightMost = node;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                
            }
        }
        return lca( root, leftMost, rightMost );
    }
};