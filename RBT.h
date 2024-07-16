#ifndef _RBT_H_
#define _RBT_H_

typedef struct Node {
    int          key;
    char         color;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

Node* newNode(int key);
void rotateLeft( Node** T, Node* x);
void rotateRight(Node** T, Node* y);
void KeyInsert(Node** T, int key);
void printElements(Node* root);
Node* Initialize();
Node* Search(Node* root,int key);

#endif