// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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

   /*
  Logic - SF. Note the recursing part here with middle
  Code - Recursion
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {      
      return convertToBST(nums, 0, nums.size());
    }
  
   TreeNode* convertToBST(vector<int>& nums, int l, int r) {
      if(l>=r) return NULL;
      
      int m =(l+r)/2;
      TreeNode* root = new TreeNode(nums[m]);
      root->left = convertToBST(nums, l, m);
      root->right = convertToBST(nums, m+1, r);
      return root;
    }
};