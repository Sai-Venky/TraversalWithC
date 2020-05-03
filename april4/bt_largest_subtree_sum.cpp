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

int findMaxSubtreeOfBT(node * root) {
    int sum = 0, right = 0, left =0;
    if (root != NULL) {
        sum = sum + root->key;
        if(root->left !=NULL) {
            sum = sum + findMaxSubtreeOfBT(root->left);
        }
        if(root->right !=NULL) {
            sum = sum + findMaxSubtreeOfBT(root->right);
        }
        if(sum > maxSum) {
            maxSum = sum;
        }
    }
    return sum;
}

int main(){
    struct node *root = newNode(-10);
    root->left = newNode(-2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(-5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(-7); 
    cout<<findMaxSubtreeOfBT(root);
    cout<<"Max Sum is"<<maxSum;
    return 0;
}   