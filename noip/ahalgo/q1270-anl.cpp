#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

struct List_Node {
    int val, prev, next;
} nodes[500005];

const int IDX_HEAD = 0, IDX_TAIL = 1;

int m, opt, vl, cur = 1, tot = 1;

void printall() {
    int itr = IDX_HEAD;
    while (itr != IDX_TAIL) {
        if (itr == cur)
            printf("[%d] ", nodes[itr].val);
        else
            printf("%d, ", nodes[itr].val);
        itr = nodes[itr].next;
    }
    putchar('\n');
}

int main(int argc, char *argv[]) {
    freopen("./q1270-in.txt", "r", stdin);

    scanf("%d", &m);

    nodes[IDX_HEAD].prev = 0;
    nodes[IDX_HEAD].next = 1;
    nodes[IDX_TAIL].prev = 0;
    nodes[IDX_TAIL].next = 1;

    for (int idx_opt = 0; idx_opt < m; ++idx_opt) {
        scanf("%d", &opt);
        if (!opt) {
            scanf("%d", &vl);
            ++tot;
            nodes[tot].val = vl;
            nodes[tot].next = cur;
            nodes[tot].prev = nodes[cur].prev;
            nodes[nodes[cur].prev].next = tot;
            nodes[cur].prev = tot;
            cur = tot;
        } else if (opt == 1) {
            scanf("%d", &vl);
            if (vl > 0)
                for (int k = 0; k < vl; ++k)
                    cur = nodes[cur].next;
            else
                for (int k = 0; k < -vl; ++k)
                    cur = nodes[cur].prev;
        } else {
            nodes[nodes[cur].next].prev = nodes[cur].prev;
            nodes[nodes[cur].prev].next = nodes[cur].next;
            cur = nodes[cur].next;
        }
        //printall();
    }

    for (int k = nodes[IDX_HEAD].next; k != IDX_TAIL; k = nodes[k].next)
        printf("%d ", nodes[k].val);
    putchar('\n');

    return 0;
}
