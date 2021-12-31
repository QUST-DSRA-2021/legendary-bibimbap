#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

class Linked_List {

private:
    struct List_Node {
        int data;
        struct List_Node *next;
        List_Node(int x = 0) : data(x), next(nullptr) {}
    } *head;
    int length;

public:
    /** Initialize the data structure here. */
    Linked_List() : head(new List_Node), length(0) {}

    virtual ~Linked_List() {}

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int res;
        if (0 <= index && index < length) {
            struct List_Node * q = head;
            for (int k = 0; k <= index; ++k)
                q = q->next;
            res = q ? (q->data) : 0;
        } else
            res = 0;
        printf("Value == %d get√, at index[ %d ]\n", res, index);
        return res;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void add_at_head(int val) {
        return add_at_index(0, val);
    }

    /** Append a node of value val to the last element of the linked list. */
    void add_at_tail(int val) {
        return add_at_index(length, val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void add_at_index(int index, int val) {
        if (index < 0)
            return add_at_tail(val);
        else if (0 <= index && index <= length) {
            struct List_Node * q = head;
            for (int k = 0; k < index; ++k)
                q = q->next;
            struct List_Node * insertion = new List_Node(val);
            insertion->next = q->next;
            q->next = insertion;
            ++length;
            return;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void delete_at_index(int index) {
        if (0 <= index && index < length) {
            struct List_Node * q = head;
            for (int k = 0; k < index; ++k)
                q = q->next;
            struct List_Node * deletion = q->next;
            q->next = q->next->next;
            delete deletion;
            --length;
            return;
        }
    }

} *qux;

int main(int argc, char *argv[]) {
    qux = new Linked_List();

    qux->add_at_head(1);
    qux->add_at_tail(3);
    qux->add_at_index(1, 2);
    qux->get(1);
    qux->delete_at_index(1);
    qux->get(1);

    delete qux;
    return 0;
}
