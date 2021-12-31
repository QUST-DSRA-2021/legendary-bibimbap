#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, curval;
char opt[10];

struct Node {
    int val;
    struct Node *parent,
                *lchild,
                *rchild;
} *root;

void printall_preorder(struct Node *rt) {
    if (rt != nullptr) {
        printf(" %d", rt->val);
        printall_preorder(rt->lchild);
        printall_preorder(rt->rchild);
    }
}

void printall_inorder(struct Node *rt) {
    if (rt != nullptr) {
        printall_inorder(rt->lchild);
        printf(" %d", rt->val);
        printall_inorder(rt->rchild);
    }
}

void printall(struct Node *rt) {
    printall_inorder(rt);
    putchar('\n');
    printall_preorder(rt);
    putchar('\n');
}

void insert_value(int _newvalue) {
    if (root != nullptr) {
        struct Node * psi = nullptr;
        struct Node * phi = root;
        while (phi != nullptr) {
            psi = phi;
            phi = (_newvalue <= phi->val) ? (phi->lchild) : (phi->rchild);
        }
        struct Node * _newnode = (struct Node *)malloc(sizeof(struct Node));
        _newnode->val = _newvalue;
        _newnode->parent = psi;
        ((_newvalue <= psi->val) ? (psi->lchild) : (psi->rchild)) = _newnode;
        _newnode->lchild = _newnode->rchild = nullptr;
    } else {
        root = (struct Node *)malloc(sizeof(struct Node));
        root->val = _newvalue;
        root->parent = root->lchild = root->rchild = nullptr;
    }
}

bool search_value(struct Node *rt, int _targetval) {
    if (rt != nullptr) {
        if (rt->val == _targetval)
            return true;
        else if (_targetval < rt->val)
            return search_value(rt->lchild, _targetval);
        else
            return search_value(rt->rchild, _targetval);
    } else
        return false;
}

void delete_value(struct Node *rt, int _targetval) {
    if (rt != nullptr) {
        if (rt->val == _targetval) {
            if (rt == root)
                root = nullptr;
            else {
                bool _onleft = (rt == rt->parent->lchild);
                if (rt->lchild != nullptr && rt->rchild != nullptr) {
                    struct Node * _todelete = rt->rchild;
                    while (_todelete->lchild != nullptr)
                        _todelete = _todelete->lchild;
                    rt->val = _todelete->val;
                    delete_value(_todelete, _todelete->val);
                } else if (rt->lchild != nullptr && rt->rchild == nullptr) {
                    rt->lchild->parent = rt->parent;
                    (_onleft ? (rt->parent->lchild) : (rt->parent->rchild)) = rt->lchild;
                } else if (rt->lchild == nullptr && rt->rchild != nullptr) {
                    rt->rchild->parent = rt->parent;
                    (_onleft ? (rt->parent->lchild) : (rt->parent->rchild)) = rt->rchild;
                } else {
                    if (_onleft)
                        rt->parent->lchild = nullptr;
                    else
                        rt->parent->rchild = nullptr;
                }
            }
        }
        else if (_targetval < rt->val)
            delete_value(rt->lchild, _targetval);
        else
            delete_value(rt->rchild, _targetval);
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    for (int k = 0; k != m; ++k) {
        scanf("%s", opt);
        if (!strcmp(opt, "print"))
            printall(root);
        else {
            scanf("%d", &curval);
            if (!strcmp(opt, "insert"))
                insert_value(curval);
            else if (!strcmp(opt, "find"))
                printf(search_value(root, curval) ? "yes\n" : "no\n");
            else
                delete_value(root, curval);
        }
    }
    return 0;
}
