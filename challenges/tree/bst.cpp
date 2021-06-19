#include<iostream>
using namespace std;


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

void inorderTraversalOfBST (node* root) {
    if (root != NULL) {
    int rootValue = root->key;
    inorderTraversalOfBST(root->left);
    cout << rootValue << " ";
    inorderTraversalOfBST(root->right);
    }
}

struct node* searchNodeInBST (struct node* root, int value) {
    int rootValue = root->key;
    if(rootValue == value) {
        return root;
    } else if (root == NULL) {
        return NULL;
    }

    if(value > rootValue) {
        return searchNodeInBST(root->right, value);
    } else {
        return searchNodeInBST(root->left, value);
    }
}

struct node* minimumNodeToRight (struct node* root) {
    if (root->left) {
        return minimumNodeToRight(root->left);
    } else {
        return root;
    }

}

struct node* deleteNode(struct node* root, int key) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct node* temp = minimumNodeToRight(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->key = temp->key; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 


struct node* insertNodeInBST (struct node* root, int value) {
    if(root == NULL) {
        return newNode(value);
    }
    int rootValue = root->key;

    if(value > rootValue) {
        root->right = insertNodeInBST(root->right, value);
    } else if (value < rootValue) {
        root->left = insertNodeInBST(root->left, value);
    }
    return root;
}

int main(){
    struct node *root = newNode(5);
    root = insertNodeInBST(root, 7);
    root = insertNodeInBST(root, 2);
    root = insertNodeInBST(root, 1);
    root = insertNodeInBST(root, 0);
    root = insertNodeInBST(root, 8);
    root = insertNodeInBST(root, 4);

    node * searchNode = searchNodeInBST(root, 8);
    if(searchNode) {
        cout<<searchNode->key;
    }

    root = deleteNode(root, 8);
    inorderTraversalOfBST(root);
    return 0;
}   