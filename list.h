typedef struct node {
    struct node *next;
    int value;
} Node;

static inline Node* InitNode(int value) {
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}

static inline void PrintNode(Node *pNode) {
    if (NULL == pNode)
        return;
    Node *ptr = pNode;
    for (; ptr != NULL; ptr = ptr->next) {
        printf("%d ->", ptr->value);
    }
    printf("\n");
}

static inline Node * InsertNode(Node *pInsertNode, Node *pToInsert) {
    if (NULL == pToInsert)
        return NULL;
    Node *pTail = pToInsert;
    while (NULL != pTail->next) pTail = pTail->next;
    pTail->next = pInsertNode->next;
    pInsertNode->next = pToInsert;
    return pToInsert;
}

static inline Node* merge(Node *phead1, Node *phead2) {
    if (NULL == phead1)
        return phead2;
    if (NULL == phead2)
        return phead1;
    // 1 3 5
    // 2 6 7
    Node *pitr1 = phead1;
    Node *pitr2 = phead2;
    Node *tmp = NULL;
    while (NULL != pitr2) {
        if (NULL == pitr1->next) {
            tmp = pitr2->next;
            pitr2->next = pitr1->next;
            pitr1->next = pitr2;
            pitr2 = tmp;
            continue;
        }
        if (!(pitr1->value <= pitr2->value && pitr1->next->value >= pitr2->value)) {
            pitr1 = pitr1->next;
            continue;
        }
        tmp = pitr2->next;
        pitr2->next = pitr1->next;
        pitr1->next = pitr2;
        pitr2 = tmp;
    }
    return phead1;
}

static inline Node* sort(Node *phead) {
    if (NULL == phead)
        return phead;
    int length = 0;
    int middle = 0;
    Node *ptr = phead;
    Node *pnewhead1;
    Node *pnewhead2;
    while (ptr != NULL) {
        length++;
        ptr = ptr->next;
    }
    // 45 
    // 44
    // 54
    if (2 == length) {
        if (phead <= phead->next)
            return phead;
        else {
            ptr = phead->next;
            phead->next = NULL;
            return merge(ptr, phead);
        }
    }
    else if (1 == length) {
        return phead;
    }
    middle = length / 2;
    ptr = phead;
    while (middle-- > 0) {
        ptr = ptr->next;
    }
    pnewhead2 = ptr->next;
    ptr->next = NULL;
    pnewhead1 = phead;
    return merge(sort(pnewhead1), sort(pnewhead2)); 
}
