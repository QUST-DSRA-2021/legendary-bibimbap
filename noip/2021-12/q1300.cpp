#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
using namespace __gnu_cxx;

struct Node {
    int val;
    struct Node *lchild,
                *rchild,
                *parent;
} *root;

stack <struct Node *> stk;
queue <struct Node *> que;

int m, curidx;

void nodesort(struct Node *rt) {
    struct Node * maxnode = rt;
    if (rt->lchild != nullptr)
        if (rt->lchild->val > maxnode->val)
            maxnode = rt->lchild;
    if (rt->rchild != nullptr)
        if (rt->rchild->val > maxnode->val)
            maxnode = rt->rchild;
    if (maxnode != rt) {
        swap(maxnode->val, rt->val);
        nodesort(maxnode);
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    // Tree Building
    root = (struct Node *)malloc(sizeof(struct Node));
    root->parent = nullptr;
    que.push(root);
    for (int k = 0; k != m; ++k) {
        scanf("%d", &curidx);
        struct Node * newnode = que.front();
        newnode->val = curidx;
        newnode->lchild = (struct Node *)malloc(sizeof(struct Node));
        newnode->rchild = (struct Node *)malloc(sizeof(struct Node));
        newnode->lchild->parent = newnode;
        newnode->rchild->parent = newnode;
        que.pop();
        que.push(newnode->lchild);
        que.push(newnode->rchild);
    }
    // Clearing Unused Nodes
    while (!que.empty()) {
        struct Node * todelete = que.front();
        ((todelete == todelete->parent->lchild) ? todelete->parent->lchild : todelete->parent->rchild) = nullptr;
        que.pop();
    }
    // Max-Heapify
    stk.push(root);
    que.push(root);
    for (int k = 0; k != m >> 1; ++k) {
        struct Node *newnode = que.front();
        if (newnode->lchild != nullptr) {
            stk.push(newnode->lchild);
            que.push(newnode->lchild);
        }
        if (newnode->rchild != nullptr) {
            stk.push(newnode->rchild);
            que.push(newnode->rchild);
        }
        que.pop();
    }
    while (!que.empty())
        que.pop();
    while (!stk.empty()) {
        nodesort(stk.top());
        stk.pop();
    }
    // Tree Outputting
    que.push(root);
    for (int k = 0; k != m; ++k) {
        struct Node *newnode = que.front();
        /* printf("node %d: key = %d, ", k + 1, newnode->val);
        if (newnode->parent != nullptr)
            printf("parent key = %d, ", newnode->parent->val);
        if (newnode->lchild != nullptr) {
            printf("left key = %d, ", newnode->lchild->val);
            que.push(newnode->lchild);
        }
        if (newnode->rchild != nullptr) {
            printf("right key = %d, ", newnode->rchild->val);
            que.push(newnode->rchild);
        }
        putchar('\n'); */
        printf(" %d", newnode->val);
        if (newnode->lchild != nullptr)
            que.push(newnode->lchild);
        if (newnode->rchild != nullptr)
            que.push(newnode->rchild);
        que.pop();
    }
    putchar('\n');
    return 0;
}
