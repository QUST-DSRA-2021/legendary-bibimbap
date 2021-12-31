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
    char val;
    struct Node *lchild,
                *rchild,
                *parent;
} *root;

queue <struct Node *> que;

char st[1001];

bool nonnull(struct Node *nd) {
    if (nd != nullptr) {
        return (nd->val != '#');
    } else
        return false;
}

bool judge(struct Node *rt) {
    if (nonnull(rt->lchild) && nonnull(rt->rchild)) {
        return judge(rt->lchild) && judge(rt->rchild);
    } else if (!nonnull(rt->lchild) && !nonnull(rt->rchild))
        return true;
    else return false;
}

int main(int argc, char *argv[]) {
    scanf("%s", st);
    int m = strlen(st);
    // Tree Building
    root = (struct Node *)malloc(sizeof(struct Node));
    root->parent = nullptr;
    que.push(root);
    for (int k = 0; k != m; ++k) {
        struct Node * newnode = que.front();
        newnode->val = st[k];
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
    if (judge(root))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
