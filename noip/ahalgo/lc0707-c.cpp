#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node {
    int val;
    /**
     * In Binary Tree, `*phi` refers to the Right Child `*rchild`
        while `*psi` refers to the Left Child `*lchild`;
     * In Linked List, `*phi` refers to the Previous Node `*prev`
        while `*psi` refers to the Next Node `*next`;
     */
    struct Node *phi, *psi;
};

struct Linked_List {
    struct Node *head, *tail;
};

struct Linked_List *Linked_List_Construct() {
    Linked_List * obj = (struct Linked_List *)malloc(sizeof(struct Linked_List));
    obj->head = (struct Node*)malloc(sizeof(struct Node));
    obj->tail = (struct Node*)malloc(sizeof(struct Node));
    obj->head->prev = nullptr;
    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;
    obj->tail->next = nullptr;
    return obj;
}

struct Linked_List *l1st;

int main(int argc, char *argv[]) {
    l1st = Linked_List_Construct();
    return 0;
}
