#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

struct Node {
    int idx, depth, num_children;
    struct Node *parent, **children;
} *root, *treenodes[100000];

void preorder(struct Node *rt) {
    if (rt != nullptr)
        for (int k = 0; k != rt->num_children; ++k) {
            rt->children[k]->depth = rt->depth + 1;
            preorder(rt->children[k]);
        }
}

int m, cur_idx, m_ch, cur_new_child;

int main(int argc, char *argv[]) {
    freopen("./q1293-in.txt", "r", stdin);
    scanf("%d", &m);
    for (int k = 0; k != m; ++k) {
        scanf("%d %d", &cur_idx, &m_ch);
        if (treenodes[cur_idx] == nullptr) {
            treenodes[cur_idx] = (struct Node *)malloc(sizeof(struct Node));
            treenodes[cur_idx]->idx = cur_idx;
            treenodes[cur_idx]->depth = 0;
            treenodes[cur_idx]->parent = nullptr;
        }
        treenodes[cur_idx]->num_children = m_ch;
        treenodes[cur_idx]->children = (struct Node **)calloc(m_ch, sizeof(struct Node *));
        for (int l = 0; l != m_ch; ++l) {
            scanf("%d", &cur_new_child);
            if (treenodes[cur_new_child] == nullptr) {
                treenodes[cur_new_child] = (struct Node *)malloc(sizeof(struct Node));
                treenodes[cur_new_child]->idx = cur_new_child;
                treenodes[cur_new_child]->depth = 0;
            }
            treenodes[cur_new_child]->parent = treenodes[cur_idx];
            treenodes[cur_idx]->children[l] = treenodes[cur_new_child];
        }
    }
    root = treenodes[cur_idx];
    while (root->parent != nullptr)
        root = root->parent;
    preorder(root);
    for (int k = 0; k != m; ++k) {
        printf("node %d: ", treenodes[k]->idx);
        if (treenodes[k]->parent != nullptr)
            printf("parent = %d, ", treenodes[k]->parent->idx);
        else
            printf("parent = -1, ");
        printf("depth = %d, ", treenodes[k]->depth);
        if (treenodes[k]->parent != nullptr) {
            if (treenodes[k]->num_children != 0)
                printf("internal node, [");
            else
                printf("leaf, [");
        } else
            printf("root, [");
        for (int l = 0; l != treenodes[k]->num_children; ++l) {
            printf("%d", treenodes[k]->children[l]->idx);
            if (l + 1 != treenodes[k]->num_children)
                printf(", ");
        }
        printf("]\n");
    }
    return 0;
}
