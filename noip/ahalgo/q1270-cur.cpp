#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

class Linked_List {
public:
    struct List_Node {
        int val;
        struct List_Node *prev, *next;
    } *head, *tail;
    int length;

    Linked_List() {
        head = (struct List_Node *)malloc(sizeof(struct List_Node));
        tail = (struct List_Node *)malloc(sizeof(struct List_Node));
        head->prev = nullptr;
        head->next = tail;
        tail->prev = head;
        tail->next = nullptr;
        length = 0;
    }

    virtual ~Linked_List() {}

    struct List_Node * __new_node__(struct List_Node *v, int x, bool rev = false) {
        struct List_Node * q = (struct List_Node *)malloc(sizeof(struct List_Node));
        q->val = x;
        if (rev) {
            q->prev = v->prev;
            q->next = v;
            v->prev->next = q;
            v->prev = q;
        } else {
            q->prev = v;
            q->next = v->next;
            v->next->prev = q;
            v->next = q;
        }
        ++length;
        return q;
    }

    struct List_Node * __del_node__(struct List_Node *v, bool rev = false) {
        v->next->prev = v->prev;
        v->prev->next = v->next;
        struct List_Node * q = rev ? v->prev : v->next;
        free(v);
        --length;
        return q;
    }

    int get_index_val(int idx) {
        int _idx = idx % length;
        if (_idx < 0)
            _idx += length;
        int mid = length >> 1;
        if (_idx < mid) {
            struct List_Node * itr = head->next;
            for (int k = 0; k < _idx; ++k)
                itr = itr->next;
            return itr->val;
        } else {
            struct List_Node * itr = tail;
            for (int k = 0; k < (length - _idx); ++k)
                itr = itr->prev;
            return itr->val;
        }
    }

    int get_head_val(bool rev = false) {
        return rev ? tail->prev->val : head->next->val;
    }

    struct List_Node * get_head_ptr(bool rev = false) {
        return rev ? tail : head;
    }

    struct List_Node * push_tail(int x = 0, bool rev = false) {
        return __new_node__(rev ? head : tail, x, !rev);
    }

    struct List_Node * pop_tail(bool rev = false) {
        return __del_node__(rev ? head->next : tail->prev, !rev);
    }

    void clearall() {
        while (length)
            pop_tail();
        return;
    }

    void printall(bool rev = false) {
        printf("%d Nodes: ", length);
        if (rev)
            for (struct List_Node * itr = tail->prev; itr != head; itr = itr->prev)
                printf("%d, ", itr->val);
        else
            for (struct List_Node * itr = head->next; itr != tail; itr = itr->next)
                printf("%d, ", itr->val);
        putchar('\n');
        return;
    }
} l1st;


int main(int argc, char *argv[]) {

    l1st.printall();

    for (int k = 0; k != 5; ++k) {
        l1st.push_tail(k);
        l1st.printall();
    }

    for (int k = 0; k != l1st.length; ++k)
        printf("Element[%d] == %d\n", k, l1st.get_index_val(k));

    return 0;
}

