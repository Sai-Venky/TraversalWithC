// https://leetcode.com/problems/binary-tree-cameras

// Note the use of logic here to install the cameras.
//-1: camera not required
//0: i am a camera
//1: i need a camera

class Solution {
public:
    int helper(TreeNode* root,int& count){
        if(root==NULL) return -1;
        
        int left=helper(root->left,count);
        int right=helper(root->right,count);
        //if either of my child needs a camera i need to acquire a camera myself
        if(left==1 || right==1){
            //count of cameras increases
            count++;
            //now i pass a sign that i am a camera
            return 0;
        }
        //if either of my child is a camera then that means i dont need a camera 
        else if(left==0 || right==0) return -1;
        //last case which includes the case when neither of my children
        //need a camera but i do
        //this may happen when my children's child is a camera
        return 1;
    }
    int minCameraCover(TreeNode* root) {
        int count=0;
        int ans=helper(root,count);
        //if ans was 1 that means the root itself needs a camera
        //this is the edge case
        ans=ans==1?count+1:count;
        return ans;
    }
};


class Solution {
public:
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 1) res++;
        return res;
    }
    
private:
    int res = 0;
    
    int dfs(TreeNode* root) {
        if (!root) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        if (left == 1 || right == 1) {
            res++;
            return -1;
        }
        
        else if (left == -1 || right == -1)
            return 0;
        
        else return 1;
    }
};