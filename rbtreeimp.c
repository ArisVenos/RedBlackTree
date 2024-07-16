#include<stdio.h>
#include<stdlib.h>

#define RED   'R'
#define BLACK 'B'


typedef struct Node {
    int          key;
    char         color;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

// Gia to initialize kai dieukolhnsh tou kwdika
struct Node  NULLNode;
Node* nulln = &NULLNode;

Node* Root = NULL;

Node* newNode(int key)
{
    Node *temp   = (Node*) malloc(sizeof(Node));
    temp->key    = key;
    temp->color  = RED;
    temp->left   = NULL;
    temp->right  = NULL;
    temp->parent = NULL;

    return temp;
}

void rotateLeft( Node** T, Node* x)
{
    Node *y  = x->right;    //  y to deksia kommati
    x->right = y->left;     // to aristoro kommati tou y ginetai deksia tou x
    if (y->left != nulln)
        y->left->parent = x;
    y->parent = x->parent;  
    if (x->parent == nulln)
        *T = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left   = x;            // To x paei aristera sto y
    x->parent = y;
}

void rotateRight(Node** T, Node* y)
{
    Node *x  = y->left;     //y to aristera kommati tou x
    y->left  = x->right;    // to deksia kommati tou x ginetai aristera toy y
    if (x->right != nulln)
        x->right->parent = y;
    x->parent = y->parent;  
    if (y->parent == nulln)
        *T = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left  = x;
    x->right  = y;         // to y paei dekisa sto x
    y->parent = x;
}

void InsertFixup(Node** Root, Node* New)
{
    Node* temp;
    while (New->parent->color == RED)
    {
        if (New->parent == New->parent->parent->left)
        {
            temp = New->parent->parent->right;
            if (temp->color == RED)
            {
                New->parent->color = BLACK;
                temp->color = BLACK;
                New->parent->parent->color = RED;
                New = New->parent->parent;
            }
            else {
                if (New == New->parent->right)
                {
                    New = New->parent;
                    rotateLeft(Root, New);
                }
                New->parent->color = BLACK;
                New->parent->parent->color = RED;
                rotateRight(Root, New->parent->parent);
            }
        }
        else
        {
            temp = New->parent->parent->left;
            if (temp->color == RED)
            {
                New->parent->color = BLACK;
                New->color = BLACK;
                New->parent->parent->color = RED;
                New = New->parent->parent;
            }
            else {
                if (New == New->parent->left)
                {
                    New = New->parent;
                    rotateRight(Root, New);
                }
                New->parent->color = BLACK;
                New->parent->parent->color = RED;
                rotateLeft(Root, New->parent->parent);
            }
        }
    }
    Root[0]->color = BLACK;
}
void KeyInsert(Node** T, int key)
{
    Node* z =  newNode(key);
    Node* y =  nulln;
    Node* x = *T;

    // Thesh tou neou node me vash ta key
    while (x != nulln) {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if (y == nulln)
        *T = z;
    else if (z->key < y->key)
        y->left  = z;
    else
        y->right = z;


    z->left  = nulln;
    z->right = nulln;
    z->color = RED;

    // Fixup gia ta xrwmmata
    InsertFixup(T, z);
}

void printElements(Node* root)
{
    if (root->left != nulln)
        printElements(root->left);
        printf("%d ", root->key);
    if (root->right != nulln)
        printElements(root->right);
}

Node* Initialize() {
    Node* Root = nulln;

    return Root;
}

Node* Search(Node* root,int key) {
    if(root != nulln) {
        if(key == root->key) {
        printf("Key (%d) found.\n",key);
        return root;
        }
        else if(key > root->key) {
        Search(root->right,key);
        }
        else {
        Search(root->left,key);
        }   
    }
    else {
        printf("The tree is empty or %d is not on the tree.\n",key);
        return root;
    }
}