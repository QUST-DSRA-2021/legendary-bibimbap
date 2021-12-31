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
    bool colored;
    inline void __init__(int _value, struct Node *_parentnode, bool _colored) {
        val = _value;
        parent = _parentnode;
        lchild = nullptr;
        rchild = nullptr;
        colored = _colored;
    }
    void __printpre() {
        printf(" %d", val);
        if (lchild != nullptr)
            lchild->__printpre();
        if (rchild != nullptr)
            rchild->__printpre();
    }
    void __printin() {
        if (lchild != nullptr)
            lchild->__printin();
        printf(" %d", val);
        if (rchild != nullptr)
            rchild->__printin();
    }
    inline void printall() {
        __printin();
        putchar('\n');
        __printpre();
        putchar('\n');
    }
    bool search(int _value) {
        if (val == _value)
            return true;
        else if (_value < val)
            return (lchild != nullptr) ? lchild->search(_value) : false;
        else
            return (rchild != nullptr) ? rchild->search(_value) : false;
    }
} *root;

inline void append(struct Node **rt, int _value) {
    if ((*rt) != nullptr) {
        struct Node * psi = nullptr,
                    * phi = (*rt);
        while (phi != nullptr) {
            psi = phi;
            phi = (_value <= phi->val) ? (phi->lchild) : (phi->rchild);
        }
        // 初始化為染色節點
        struct Node * _newnode = (struct Node *)malloc(sizeof(struct Node));
        _newnode->__init__(_value, psi, true);
        if (_value <= psi->val)
            psi->lchild = _newnode;
        else
            psi->rchild = _newnode;
    } else {
        // 根節點初始化為無色節點
        (*rt) = (struct Node *)malloc(sizeof(struct Node));
        (*rt)->__init__(_value, nullptr, false);
    }
}

void remove(struct Node **rt, int _value) {
    if ((*rt) != nullptr) {
        if ((*rt)->val == _value) {
            // 找到待刪除的值！
            bool _lexist = ((*rt)->lchild != nullptr), _rexist = ((*rt)->rchild != nullptr);
            if (_lexist && _rexist) {
                // 同時存在左右子樹的情況
                // 定位到中序排列後的下一個節點
                struct Node * _todelete = (*rt)->rchild;
                while (_todelete->lchild != nullptr)
                    _todelete = _todelete->lchild;
                // 把中序排列下一位的值複製過來
                (*rt)->val = _todelete->val;
                // 然後遞歸刪除空出來的位置
                remove(&_todelete, _todelete->val);
            } else if (_lexist) {
                (*rt)->val = (*rt)->lchild->val;
                (*rt)->rchild = (*rt)->lchild->rchild;
                (*rt)->lchild = (*rt)->lchild->lchild;
            } else if (_rexist) {
                (*rt)->val = (*rt)->rchild->val;
                (*rt)->lchild = (*rt)->rchild->lchild;
                (*rt)->rchild = (*rt)->rchild->rchild;
            } else
                // 左右子樹都不存在的情況，僅需處理其父節點
                if ((*rt)->parent != nullptr)
                    (((*rt) == (*rt)->parent->lchild) ? ((*rt)->parent->lchild) : ((*rt)->parent->rchild)) = nullptr;
        } else if (_value < (*rt)->val)
            // 向待刪除值<當前節點數值，向左子樹繼續遞歸尋找
            remove(&((*rt)->lchild), _value);
        else
            // 向待刪除值>當前節點數值，向右子樹繼續遞歸尋找
            remove(&((*rt)->rchild), _value);
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    for (int k = 0; k != m; ++k) {
        scanf("%s", opt);
        if (!strcmp(opt, "print"))
            root->printall();
        else {
            scanf("%d", &curval);
            if (!strcmp(opt, "insert"))
                append(&root, curval);
            else if (!strcmp(opt, "find"))
                printf(root->search(curval) ? "yes\n" : "no\n");
            else
                remove(&root, curval);
        }
    }
    return 0;
}
