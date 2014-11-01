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

int printTree(bst* tree);//Prints an array in sorted manner

bst* treeInit();//Returns a new BSTree with root pointing to NULL

node* nodeInit(int value);//Creates a Node with the data set to the argument given
							//Left and right pointers are set to null

void insertNode(bst* treeOrg, int value);//Insertion of a node
											//Assumes such a value does not pre-exist in the tree

node* findNode(bst* treeOrg, int value);//Returns address of a node in a tree

int findRight(node* root);// finds right most node in a tree

int indexOfLess(int value, int array[], int high);

void deletion(bst *tree, int x);//Deletes a node assuming three possible cases 

void case_a(node* par, node* loc, bst* tree);

void case_b(node* par, node* loc, bst* tree);

void case_c(node* par, node* loc, bst* tree);

void bfs(bst *tree); //Breadth first print of a BStree

//Functions defined for the traversal portion
void printPre(int inOrder[], int postOrder[], int inLow, int inHigh, int postLow, int postHigh);//Prints pre order w/o making a tree

int indexOf(int value, int array[]);

bst* treeBuild(int inOrder[], int postOrder[], int size);//Builds a tree from in and pre order traversals

node* nodePre(int inOrder[], int postOrder[], int inLow, int inHigh, int postLow, int postHigh);//Assigns nodes to tree to give proper root from in and post order traversals

int printTreePre(node* root);//Prints a tree in pre order


// TODO: Write functions to add/remove an element from the binary tree. 
// TODO: Write a function to search if an element belongs to the BST
// TODO: Write a function to print out the whole BST


#endif // BST_H

