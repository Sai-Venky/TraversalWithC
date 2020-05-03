#include<iostream>
using namespace std;


struct node {
    int key;
    struct node *left;
    struct node *right;
};

int maxSum = 0;
struct node* newNode(int x) {
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->key = x;
    root->left = root->right = NULL;
    return root;
}

void inorderTraversalOfBT (node* root) {
    if (root != NULL) {
    int rootValue = root->key;
    inorderTraversalOfBT(root->left);
    cout << rootValue << " ";
    inorderTraversalOfBT(root->right);
    }
}

void depthOfTree(node * root, int height, int *maxHeight) {
    if(root == NULL ) {
        if(height > *maxHeight) {
            *maxHeight = height;
        }
    } else {
        depthOfTree(root->left, height + 1, maxHeight);
        depthOfTree(root->right, height + 1, maxHeight);
    }
}

int height(node * root) {
    int height = 0 ;
    int heightTree = 0;
    int *maxHeight = &heightTree;
    if(root == NULL) {
        return 0;
    }

    depthOfTree(root, height, maxHeight);
    return heightTree;
}

int minTimeToBurn = 0;
int minTime(node *root, int target) {
    if(root == NULL) {
        return 0;
    }
    int key = root->key;
    if(key == target) {
        return 1;
    }
    int timetoReachTillHereFromLeft = minTime(root->left, target);
    if(timetoReachTillHereFromLeft > 0) {
        cout<<"\nThe time taken is "<<timetoReachTillHereFromLeft<<" Key is "<<key;
        int depth = height(root->right);
        cout<<"\n Right Depth is "<<depth;
        int totalTimeToBurnSubtree = timetoReachTillHereFromLeft + depth;
        if(totalTimeToBurnSubtree > minTimeToBurn)    {
            minTimeToBurn = totalTimeToBurnSubtree;
        }
        return timetoReachTillHereFromLeft + 1;   
    }
    int timetoReachTillHereFromRight = minTime(root->right, target);
    if(timetoReachTillHereFromRight > 0) {
        cout<<"\nThe time taken is "<<timetoReachTillHereFromRight<<" Key is "<<key;
        int depth = height(root->left);
        cout<<"\n Left Depth is "<<depth;
        int totalTimeToBurnSubtree = timetoReachTillHereFromLeft + depth;
        if(totalTimeToBurnSubtree > minTimeToBurn)    {
            minTimeToBurn = totalTimeToBurnSubtree;
        }       
        return timetoReachTillHereFromRight + 1;
    }

    return 0;
}

int main(){
    node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->left->left->left = newNode(8); 
    root->left->right->left = newNode(9); 
    root->left->right->right = newNode(10); 
    root->left->right->left->left = newNode(11); 
  
    // target node is 8 
    int target = 11; 
    int output = minTime(root, target);
    cout << "\n\n The output is "<<minTimeToBurn; 
  
    return 0; 
}   