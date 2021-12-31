#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

struct Node {
    int idx, size;
    struct Node *sup;
} *ufsets[100000];

struct Node *find_superior(struct Node *x) {
    // x->sup = find_superior(x->sup) 为路径压缩(扁平化)操作
    return ((x->sup != x) ? (x->sup = find_superior(x->sup)) : x);
}

void union_nodes(struct Node *x, struct Node *y) {
    // 合并结点簇是对两簇结点的祖先进行的操作，遂先溯源
    struct Node * sup_x = find_superior(x), * sup_y = find_superior(y);
    if (sup_x != sup_y) {
        if (sup_x->size >= sup_y->size) {
            // 保证size较小者向较大者进行合并
            sup_y->sup = sup_x;
            sup_x->size += sup_y->size;
        } else {
            sup_x->sup = sup_y;
            sup_y->size += sup_x->size;
        }
    }
}

bool judge_union(struct Node *x, struct Node *y) {
    return (find_superior(x) == find_superior(y));
}

int m, n, q;

int main(int argc, char *argv[]) {
    freopen("./q1312-in.txt", "r", stdin);

    scanf("%d", &m);
    // Initialization
    for (int k = 0; k != m; ++k) {
        ufsets[k] = (struct Node *)malloc(sizeof(struct Node));
        ufsets[k]->idx = k;
        ufsets[k]->size = 1;
        ufsets[k]->sup = ufsets[k];
    }

    scanf("%d", &n);
    // Union
    for (int k = 0; k != n; ++k) {
        int psi, phi;
        scanf("%d %d", &psi, &phi);
        if ((--psi) < (--phi))
            union_nodes(ufsets[psi], ufsets[phi]);
        else
            union_nodes(ufsets[phi], ufsets[psi]);
    }

    /*for (int k = 0; k != m; ++k)
        printf("Node[%d]->size == %d, Node[%d]->sup == Node[%d], find: %d\n", k, ufsets[k]->size, k, ufsets[k]->sup->idx, find_superior(ufsets[k])->idx);*/

    int res = 0;
    for (int k = 0; k != m; ++k) {
        struct Node * cur_sup = find_superior(ufsets[k]);
        printf("[%d]:%d,%d\n", k, cur_sup->idx, cur_sup->size);
        if (res < cur_sup->size)
            res = cur_sup->size;
    }
    printf("%d\n", res);

    return 0;
}
