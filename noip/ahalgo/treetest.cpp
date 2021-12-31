#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

struct Node {
    int val;
    struct Node *psi, *phi;
} *root;

void preorder(struct Node *rt) {
    if (rt != nullptr) {
        printf("%d, ", rt->val);
        preorder(rt->psi);
        preorder(rt->phi);
    }
    return;
}

int main(int argc, char *argv[]) {
    root = (struct Node *)malloc(sizeof(struct Node));
    root->val = 39;
    root->psi = (struct Node *)malloc(sizeof(struct Node));
    root->psi->val = 1;
    root->psi->psi = (struct Node *)malloc(sizeof(struct Node));
    root->psi->psi->val = 2;
    root->psi->psi->psi = (struct Node *)malloc(sizeof(struct Node));
    root->psi->psi->psi->val = 3;
    root->psi->psi->psi->psi = (struct Node *)malloc(sizeof(struct Node));
    root->psi->psi->psi->psi->val = 4;
    root->psi->psi->psi->phi = (struct Node *)malloc(sizeof(struct Node));
    root->psi->psi->psi->phi->val = 4;
    root->psi->psi->phi = (struct Node *)malloc(sizeof(struct Node));
    root->psi->psi->phi->val = 3;
    root->psi->psi->phi->psi = (struct Node *)malloc(sizeof(struct Node));
    root->psi->psi->phi->psi->val = 4;
    root->psi->psi->phi->phi = (struct Node *)malloc(sizeof(struct Node));
    root->psi->psi->phi->phi->val = 4;
    root->psi->phi = (struct Node *)malloc(sizeof(struct Node));
    root->psi->phi->val = 2;
    root->psi->phi->psi = (struct Node *)malloc(sizeof(struct Node));
    root->psi->phi->psi->val = 3;
    root->psi->phi->psi->psi = (struct Node *)malloc(sizeof(struct Node));
    root->psi->phi->psi->psi->val = 4;
    root->psi->phi->psi->phi = (struct Node *)malloc(sizeof(struct Node));
    root->psi->phi->psi->phi->val = 4;
    root->psi->phi->phi = (struct Node *)malloc(sizeof(struct Node));
    root->psi->phi->phi->val = 3;
    root->psi->phi->phi->psi = (struct Node *)malloc(sizeof(struct Node));
    root->psi->phi->phi->psi->val = 4;
    root->psi->phi->phi->phi = (struct Node *)malloc(sizeof(struct Node));
    root->psi->phi->phi->phi->val = 4;
    root->phi = (struct Node *)malloc(sizeof(struct Node));
    root->phi->val = 1;
    root->phi->psi = (struct Node *)malloc(sizeof(struct Node));
    root->phi->psi->val = 2;
    root->phi->psi->psi = (struct Node *)malloc(sizeof(struct Node));
    root->phi->psi->psi->val = 3;
    root->phi->psi->psi->psi = (struct Node *)malloc(sizeof(struct Node));
    root->phi->psi->psi->psi->val = 4;
    root->phi->psi->psi->phi = (struct Node *)malloc(sizeof(struct Node));
    root->phi->psi->psi->phi->val = 4;
    root->phi->psi->phi = (struct Node *)malloc(sizeof(struct Node));
    root->phi->psi->phi->val = 3;
    root->phi->psi->phi->psi = (struct Node *)malloc(sizeof(struct Node));
    root->phi->psi->phi->psi->val = 4;
    root->phi->psi->phi->phi = (struct Node *)malloc(sizeof(struct Node));
    root->phi->psi->phi->phi->val = 4;
    root->phi->phi = (struct Node *)malloc(sizeof(struct Node));
    root->phi->phi->val = 2;
    root->phi->phi->psi = (struct Node *)malloc(sizeof(struct Node));
    root->phi->phi->psi->val = 3;
    root->phi->phi->psi->psi = (struct Node *)malloc(sizeof(struct Node));
    root->phi->phi->psi->psi->val = 4;
    root->phi->phi->psi->phi = (struct Node *)malloc(sizeof(struct Node));
    root->phi->phi->psi->phi->val = 4;
    root->phi->phi->phi = (struct Node *)malloc(sizeof(struct Node));
    root->phi->phi->phi->val = 3;
    root->phi->phi->phi->psi = (struct Node *)malloc(sizeof(struct Node));
    root->phi->phi->phi->psi->val = 4;
    root->phi->phi->phi->phi = (struct Node *)malloc(sizeof(struct Node));
    root->phi->phi->phi->phi->val = 4;

    preorder(root);
    putchar('\n');

    return 0;
}
