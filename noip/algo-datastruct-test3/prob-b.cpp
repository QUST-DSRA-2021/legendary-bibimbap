#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

struct Node {
    int idx;
    char val;
    struct Node *parent,
                *lchild,
                *rchild;
} *root, *treenodes[100001];

void preorder(struct Node *rt) {
    if (rt != nullptr)
        printf("%c", rt->val);
    if (rt->lchild != nullptr)
        preorder(rt->lchild);
    if (rt->rchild != nullptr)
        preorder(rt->rchild);
}

void inorder(struct Node *rt) {
    if (rt->lchild != nullptr)
        inorder(rt->lchild);
    if (rt != nullptr)
        printf("%c", rt->val);
    if (rt->rchild != nullptr)
        inorder(rt->rchild);
}

void postorder(struct Node *rt) {
    if (rt->lchild != nullptr)
        postorder(rt->lchild);
    if (rt->rchild != nullptr)
        postorder(rt->rchild);
    if (rt != nullptr)
        printf("%c", rt->val);
}

int m, lch, rch;
char nodename;

int main(int argc, char *argv[]) {
    // Initialization
    scanf("%d", &m);
    for (int k = 0; k != m; ++k) {
        getchar();
        scanf("%c %d %d", &nodename, &lch, &rch);
        --lch;
        --rch;

        //printf("%c %d %d\n", nodename, lch, rch);
        // Tree Building
        if (treenodes[k] == nullptr) {
            treenodes[k] = (struct Node *)malloc(sizeof(struct Node));
            treenodes[k]->idx = k;
        }
        treenodes[k]->val = nodename;
        if (lch != -1) {
            if (treenodes[lch] == nullptr) {
                treenodes[lch] = (struct Node *)malloc(sizeof(struct Node));
                treenodes[lch]->idx = lch;
            }
            treenodes[k]->lchild = treenodes[lch];
            treenodes[lch]->parent = treenodes[k];
        }
        if (rch != -1) {
            if (treenodes[rch] == nullptr) {
                treenodes[rch] = (struct Node *)malloc(sizeof(struct Node));
                treenodes[rch]->idx = rch;
            }
            treenodes[k]->rchild = treenodes[rch];
            treenodes[rch]->parent = treenodes[k];
        }
    }

    // Root Sourcing
    root = treenodes[0];
    while (root->parent != nullptr)
        root = root->parent;

    // Outputting
    preorder(root);
    putchar('\n');
    inorder(root);
    putchar('\n');
    postorder(root);
    putchar('\n');
    return 0;
}
