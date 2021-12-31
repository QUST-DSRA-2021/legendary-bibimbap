#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

struct Node {
    int idx;
    struct Node *parent,
                *lchild,
                *rchild;
} *root, *treenodes[100001];

void preorder(struct Node *rt) {
    if (rt != nullptr)
        printf(" %d", rt->idx);
    if (rt->lchild != nullptr)
        preorder(rt->lchild);
    if (rt->rchild != nullptr)
        preorder(rt->rchild);
}

void inorder(struct Node *rt) {
    if (rt->lchild != nullptr)
        inorder(rt->lchild);
    if (rt != nullptr)
        printf(" %d", rt->idx);
    if (rt->rchild != nullptr)
        inorder(rt->rchild);
}

void postorder(struct Node *rt) {
    if (rt->lchild != nullptr)
        postorder(rt->lchild);
    if (rt->rchild != nullptr)
        postorder(rt->rchild);
    if (rt != nullptr)
        printf(" %d", rt->idx);
}

int m, cur_idx, lch, rch;

int main(int argc, char *argv[]) {
    // Initialization
    //freopen("./q1295-in.txt", "r", stdin);
    scanf("%d", &m);
    for (int k = 0; k != m; ++k) {
        treenodes[k] = (struct Node *)malloc(sizeof(struct Node));
        treenodes[k]->idx = k;
        treenodes[k]->parent = nullptr;
        treenodes[k]->lchild = nullptr;
        treenodes[k]->rchild = nullptr;
    }
    for (int k = 0; k != m; ++k) {
        scanf("%d %d %d", &cur_idx, &lch, &rch);

        // Tree Building
        if (lch != -1) {
            treenodes[cur_idx]->lchild = treenodes[lch];
            treenodes[lch]->parent = treenodes[cur_idx];
        }
        if (rch != -1) {
            treenodes[cur_idx]->rchild = treenodes[rch];
            treenodes[rch]->parent = treenodes[cur_idx];
        }
    }

    // Root Sourcing
    root = treenodes[0];
    while (root->parent != nullptr)
        root = root->parent;

    // Outputting
    printf("Preorder\n");
    preorder(root);
    putchar('\n');
    printf("Inorder\n");
    inorder(root);
    putchar('\n');
    printf("Postorder\n");
    postorder(root);
    putchar('\n');
    return 0;
}
