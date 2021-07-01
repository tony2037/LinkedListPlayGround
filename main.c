#include <stdlib.h>
#include <stdio.h>
#include "list.h"

// {2, 1}
// {4, 5, 6 ,3}
int main(int argc, char **argv) {
/// generate test data
    Node *pHead1 = InitNode(1);
    Node *pHead2 = InitNode(2);
    InsertNode(pHead1, InitNode(3));
    InsertNode(pHead1, InitNode(5));
    InsertNode(pHead2, InitNode(6));
    InsertNode(pHead2, InitNode(7));
    PrintNode(pHead1);
    PrintNode(pHead2);

///
    Node *pHead = merge(pHead1, pHead2);
    PrintNode(pHead);
    pHead = sort(pHead);
    PrintNode(pHead);
    return 0;
}
