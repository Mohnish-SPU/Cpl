/*
 * Author: Mohnish
 * Binary Search Tree data structure
 */

#ifndef BST_H
#define BST_H

// Node for the link list
typedef struct Node_ node;
struct Node_ {
    int data;
    node* left;
    node* right;
};

// Link list structure
typedef struct BSTree_ {
    node* root;
} bst;

int printTree(node* root);
bst* treeInit();
node* nodeInit(int value);
bst* insertNode(bst* treeOrg, int value);
bst* removeNode(bst* treeOrg, int value);
node* findNode(bst* treeOrg, int value,node* prev, int *pos);
int findRight(node* root);

//Functions defined for the traversal portion
void printPre(int inOrder[], int postOrder[], int inLow, int inHigh, int postLow, int postHigh);
int indexOf(int value, int array[]);
bst* treeBuild(int inOrder[], int postOrder[], int size);
node* nodePre(int inOrder[], int postOrder[], int inLow, int inHigh, int postLow, int postHigh);
int printTreePre(node* root);


// TODO: Write functions to add/remove an element from the binary tree. 
// TODO: Write a function to search if an element belongs to the BST
// TODO: Write a function to print out the whole BST


#endif // BST_H

