#include<iostream>
using namespace std;

int leftSum = 0;
int rightSum = 0;
int leafSum = 0;

struct node {
    int key;
    struct node *left;
    struct node *right;
};

struct node* newNode(int x) {
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->key = x;
    root->left = root->right = NULL;
    return root;
}

void sumOfLeftBoundary(node * root) {
    if(root!=NULL && !(root->left == NULL && root->right == NULL)) {
        leftSum+=root->key;
        sumOfLeftBoundary(root->left);
    }
}

void sumOfRightBoundary(node * root) {
    if(root!=NULL && !(root->left == NULL && root->right == NULL)) {
        rightSum+=root->key;
        sumOfRightBoundary(root->right);
    }
}


void sumOfLeafBoundary(node * root) {
    if(root == NULL ) {
        return;
    }
    if(root->left == NULL && root->right == NULL) {
        leafSum+=root->key;
    }
    sumOfLeafBoundary(root->left);
    sumOfLeafBoundary(root->right);

}

int sumOfBoundaryNodes(node * root) {
    int sum = root->key;
    sumOfLeftBoundary(root->left);
    sumOfRightBoundary(root->right);
    sumOfLeafBoundary(root);
    sum = sum + leftSum + rightSum + leafSum;
    return sum;
}

int main(){
    node* root = newNode(10); 
    root->left = newNode(2); 
    root->right = newNode(5); 
    root->left->left = newNode(8); 
    root->left->right = newNode(14); 
    root->right->left = newNode(11); 
    root->right->right = newNode(3); 
    root->left->right->left = newNode(12); 
    root->right->left->right = newNode(1); 
    root->right->left->left = newNode(7); 
  
    cout << sumOfBoundaryNodes(root); 
  
    return 0;
}