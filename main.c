#include<stdio.h>
#include<stdlib.h>
#include "RBT.h"

int main(void)
{
    Node* Root = Initialize();
    
    Search(Root,3);
    KeyInsert(&Root, 3);
    KeyInsert(&Root, 5);
    KeyInsert(&Root, 7);
    KeyInsert(&Root, 4);
    KeyInsert(&Root, 22);
    KeyInsert(&Root, 1);
    KeyInsert(&Root, 11);
    KeyInsert(&Root, 17);
    KeyInsert(&Root, 20);
    KeyInsert(&Root, 10);
    KeyInsert(&Root, 26);

    printElements(Root);
    printf("\n");
    Search(Root,3);
    Search(Root,6);

    return 0;
}