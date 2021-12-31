#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

struct List_Node {
    int val;
    struct List_Node *prev, *next;
};

class Linked_List {
public:
    struct List_Node *head, *tail;
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

    int get_head_val(bool rev = false) {
        return rev ? tail->prev->val : head->next->val;
    }

    struct List_Node * get_head_ptr(bool rev = false) {
        return rev ? tail : head;
    }

    void printall(bool rev = false) {
        for (struct List_Node * itr = head->next; itr != tail; itr = itr->next)
            printf("%d\n", itr->val);
        return;
    }
} l1st;

int m, opt, val;

int main(int argc, char *argv[]) {
    scanf("%d", &m);

    struct List_Node * cur = l1st.get_head_ptr(true);

    for (int idx_opt = 0; idx_opt < m; ++idx_opt) {
        scanf("%d", &opt);
        if (opt == 2) {
            cur = l1st.__del_node__(cur);
        } else {
            scanf("%d", &val);
            if (opt) {
                if (val > 0)
                    for (int idx_step = 0; idx_step < val; ++idx_step)
                        cur = cur->next;
                else
                    for (int idx_step = 0; idx_step < -val; ++idx_step)
                        cur = cur->prev;
            } else
                cur = l1st.__new_node__(cur, val, true);
        }
    }

    l1st.printall();

    return 0;
}
