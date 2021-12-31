#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

struct Node {
    int idx, idx_prnt, idx_sib, num_deg, depth, height;
    struct Node *parent,
                *lchild,
                *rchild;
} *root, *treenodes[100001];

void preorder(struct Node *rt) {
    if (rt != nullptr) {
        //printf(" %d", rt->idx);
        int deg = 0, hgt = 0;
        // Processing the Left Subtree...
        if (rt->lchild != nullptr) {
            rt->lchild->depth = rt->depth + 1;
            rt->lchild->idx_prnt = rt->idx;
            if (rt->rchild != nullptr)
                rt->lchild->idx_sib = rt->rchild->idx;
            preorder(rt->lchild);
            ++deg;
            hgt = (rt->lchild->height + 1 > hgt) ? (rt->lchild->height + 1) : (hgt);
        }
        // Processing the Right Subtree...
        if (rt->rchild != nullptr) {
            rt->rchild->depth = rt->depth + 1;
            rt->rchild->idx_prnt = rt->idx;
            if (rt->lchild != nullptr)
                rt->rchild->idx_sib = rt->lchild->idx;
            preorder(rt->rchild);
            ++deg;
            hgt = (rt->rchild->height + 1 > hgt) ? (rt->rchild->height + 1) : (hgt);
        }
        rt->num_deg = deg;
        rt->height = hgt;
    }
}
void inorder(struct Node *rt) { if (rt != nullptr) { inorder(rt->lchild); printf(" %d", rt->idx); inorder(rt->rchild); } }
void postorder(struct Node *rt) { if (rt != nullptr) { postorder(rt->lchild); postorder(rt->rchild); printf(" %d", rt->idx); } }

int m, cur_idx, lch, rch;

int main(int argc, char *argv[]) {
    // Initialization
    freopen("./q1294-in.txt", "r", stdin);
    scanf("%d", &m);
    for (int k = 0; k != m; ++k) {
        scanf("%d %d %d", &cur_idx, &lch, &rch);

        // Tree Building
        if (treenodes[cur_idx] == nullptr) {
            treenodes[cur_idx] = (struct Node *)malloc(sizeof(struct Node));
            treenodes[cur_idx]->idx = cur_idx;
            treenodes[cur_idx]->parent = nullptr;
            treenodes[cur_idx]->idx_sib = -1;
        }
        if (lch != -1) {
            if (treenodes[lch] == nullptr) {
                treenodes[lch] = (struct Node *)malloc(sizeof(struct Node));
                treenodes[lch]->idx = lch;
                treenodes[lch]->lchild = nullptr;
                treenodes[lch]->rchild = nullptr;
                treenodes[lch]->idx_sib = -1;
            }
            treenodes[cur_idx]->lchild = treenodes[lch];
            treenodes[lch]->parent = treenodes[cur_idx];
        } else
            treenodes[cur_idx]->lchild = nullptr;
        if (rch != -1) {
            if (treenodes[rch] == nullptr) {
                treenodes[rch] = (struct Node *)malloc(sizeof(struct Node));
                treenodes[rch]->idx = rch;
                treenodes[rch]->lchild = nullptr;
                treenodes[rch]->rchild = nullptr;
                treenodes[rch]->idx_sib = -1;
            }
            treenodes[cur_idx]->rchild = treenodes[rch];
            treenodes[rch]->parent = treenodes[cur_idx];
        } else
            treenodes[cur_idx]->rchild = nullptr;
    }

    // Root Sourcing
    root = treenodes[cur_idx];
    while (root->parent != nullptr)
        root = root->parent;
    root->idx_prnt = -1;
    root->depth = 0;
    preorder(root);

    // Outputting
    for (int k = 0; k != m; ++k) {
        printf("node %d: "
                "parent = %d, "
                "sibling = %d, "
                "degree = %d, "
                "depth = %d, "
                "height = %d, "
                , k, treenodes[k]->idx_prnt, treenodes[k]->idx_sib, treenodes[k]->num_deg, treenodes[k]->depth, treenodes[k]->height);
        if (treenodes[k]->idx_prnt == -1)
            printf("root\n");
        else if (treenodes[k]->num_deg == 0)
            printf("leaf\n");
        else
            printf("internal node\n");
    }
    return 0;
}
