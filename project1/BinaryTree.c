

#include<stdlib.h>

typedef struct BinaryTreeNode{
    BinaryTreeNode* leftChild;
    BinaryTreeNode* rightChild;
    int data;
} BinaryTreeNode;

typedef struct BinaryTree{
    BinaryTreeNode* root;
} BinaryTree;


void createBinaryTree(BinaryTree* tree){
    tree->root = NULL;
}

void insertNodeBST(BinaryTreeNode* root, int item){
    if(item < root->data)
        if(root->leftChild)
            insertNodeBST(root->leftChild, item);
        else{
            root->leftChild = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
            root->leftChild = item;
        }
    else
        if(root->rightChild)
            insertNodeBST(root->rightChild, item);
        else{
            root->rightChild = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
            root->rightChild = item;
        }
}

void insertBST(BinaryTree* tree, int item){
    if(tree->root){
        insertNodeBST(tree->root, item);
    }else{
        tree->root = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
        tree->root = item;
    }
}