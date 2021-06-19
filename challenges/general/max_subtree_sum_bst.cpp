// https://www.geeksforgeeks.org/maximum-sub-tree-sum-in-a-binary-tree-such-that-the-sub-tree-is-also-a-bst/

#include<iostream>
using namespace std;

struct node {
    int key;
    struct node *left;
    struct node *right;
};

int maxSum = 0;
int dp[100];
struct node* newnode(int x) {
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->key = x;
    root->left = root->right = NULL;
    return root;
}

bool isBST(node * root, int position) {
    int keyValue = root->key;
    bool isBSTSatisfied = 1;
    if(dp[position]!=-1) {
        return dp[position];
    }
    if(root->left){
        int leftValue = root->left->key;
        if( leftValue>keyValue ) {
            isBSTSatisfied =  0;
        }
    }
    if(root->right && isBSTSatisfied){
        int rightValue = root->right->key;
        if( rightValue<keyValue ) {
            isBSTSatisfied = 0;
        }
    }
    if(root->left && isBSTSatisfied) {
        isBSTSatisfied = isBST(root->left, (2 * position));
    }
    if(root->right && isBSTSatisfied) {
        isBSTSatisfied = isBST(root->right, (2 * position) + 1);
    }

    return isBSTSatisfied;
}

int MaxSumBST(node * root, int position) {
    int sum = 0, right = 0, left =0;
    if (root != NULL) {
        sum = sum + root->key;
        if(root->left !=NULL ) {
            sum = sum + MaxSumBST(root->left, (2 * position));
        }
        if(root->right !=NULL) {
            sum = sum + MaxSumBST(root->right, (2 * position) + 1);
        }
        bool isSubtreeBST = isBST(root, position);
        dp[position] = isSubtreeBST;
        if(sum > maxSum && isSubtreeBST) {
            maxSum = sum;
        }
    }
    return sum;
}

int main() {
    memset(dp, -1, sizeof(dp)); 
    struct node* root = newnode(0); 
    root->left = newnode(8); 
    root->right = newnode(10); 
    root->left->left = newnode(5); 
    root->right->right = newnode(14); 
    root->left->left->left = newnode(4); 
    root->left->left->right = newnode(6); 
  
    MaxSumBST(root, 1); 
    cout<<maxSum;
    return 0;
}