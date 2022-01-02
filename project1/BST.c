

#include<stdlib.h>
#include<stdbool.h>

typedef struct BSTNode{
    BSTNode* leftChild;
    BSTNode* rightChild;
    int data;
} BSTNode;

typedef struct BST{
    BSTNode* root;
} BST;


void createBST(BST* tree){
    tree->root = NULL;
}

void insertNode(BSTNode* root, int item){
    if(item < root->data)
        if(root->leftChild)
            insertNode(root->leftChild, item);
        else{
            root->leftChild = (BSTNode*)malloc(sizeof(BSTNode));
            root->leftChild = item;
        }
    else
        if(root->rightChild)
            insertNode(root->rightChild, item);
        else{
            root->rightChild = (BSTNode*)malloc(sizeof(BSTNode));
            root->rightChild = item;
        }
}

void insert(BST* tree, int item){
    if(tree->root){
        insertNodeBST(tree->root, item);
    }else{
        tree->root = (BSTNode*)malloc(sizeof(BSTNode));
        tree->root = item;
    }
}