#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node {
    int val;
    struct Node *prev, *next;
} *head, *tail;

int m, cur;

int main(int argc, char *argv[]) {

    // Initialization
    head = (struct Node*)malloc(sizeof(struct Node));
    head->val = 0;
    head->next = nullptr;
    tail = head;

    // Inputting
    freopen("./arrdata.txt", "r", stdin);
    scanf("%d", &m);
    for (int k = 0; k != m; ++k) {
        scanf("%d", &cur);

        // Construction
        struct Node * q = (struct Node *)malloc(sizeof(struct Node));
        q->val = cur;
        q->next = nullptr;
        tail->next = q;
        tail = tail->next;
    }

    // Outputting
    for (struct Node * k = head->next; k != nullptr; k = k->next)
        printf("%d, ", k->val);
    putchar('\n');
    return 0;
}
