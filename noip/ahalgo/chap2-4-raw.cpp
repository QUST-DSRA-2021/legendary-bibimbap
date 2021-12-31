#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node {
    int val;
    struct Node *next;
} *head, *tail, *q;
int m, cur;

int main(int argc, char *argv[]) {
    freopen("./chap2-4-in.txt", "r", stdin);
    scanf("%d", &m);
    // Initialization
    head = nullptr;
    // Construction
    for (int k = 0; k != m; ++k) {
        scanf("%d", &cur);
        q = (struct Node *)malloc(sizeof(struct Node));
        q->val = cur;
        q->next = nullptr;
        ((head != nullptr) ? (tail->next) : head) = q;
        tail = q;
    }
    // Output
    for (q = head; q != nullptr; q = q->next)
        printf("%d, ", q->val);
    putchar('\n');
    printf("%d\n", sizeof(struct Node));
    return 0;
}
