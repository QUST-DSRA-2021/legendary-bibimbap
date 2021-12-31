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
    inline
    void __init__(int _value, struct Node *_parentnode, bool _colored) {
        val = _value;
        parent = _parentnode;
        lchild = nullptr;
        rchild = nullptr;
        colored = _colored;
    }
    inline
    void toggle() {
        colored = !colored;
    }
    inline
    void flip() { // 「翻轉」自身與左右孩子節點的顔色
        toggle();
        if (lchild != nullptr)
            lchild->toggle();
        if (rchild != nullptr)
            rchild->toggle();
    }
    void __printpre() {
        printf(colored ? " [%d]" : " %d", val);
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
    inline
    void printall() {
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

inline
struct Node * rotate(struct Node *rt) { // 俗稱「左旋」的旋邊方法，其實就是逆時針
    if (rt != nullptr)
        if (rt->rchild != nullptr) {
            struct Node * _oriroot = rt, * _newroot = rt->rchild;
            /**
             * @brief Clockwise-Rotate Function of the Edge...
             * @author sandyzikun (https://sandyzikun.github.io/)
             * @param (struct Node *)rt
             * @return NULL
             * @desc
             *    <2>              [1]
             *    / \\            // \
             *   4   [1]   =>   <2>   3
             *       / \        / \
             *      5   3      4   5
             * czk: 不多解釋，因爲我自己也解釋不清，直接看示意圖操作好了(
             */
            swap(_oriroot->colored, _newroot->colored);
            _newroot->parent = _oriroot->parent;
            if (_newroot->parent != nullptr) {
                if (_oriroot == _oriroot->parent->lchild)
                    _oriroot->parent->lchild = _newroot;
                else
                    _oriroot->parent->rchild = _newroot;
            }
            _oriroot->parent = _newroot;
            _oriroot->rchild = _newroot->lchild;
            if (_oriroot->rchild != nullptr)
                _oriroot->rchild->parent = _oriroot;
            _newroot->lchild = _oriroot;
            return rt->parent;
        }
    return rt;
}

inline
struct Node * rotrev(struct Node *rt) { // 「右旋」
    if (rt != nullptr)
        if (rt->lchild != nullptr) {
            struct Node * _oriroot = rt, * _newroot = rt->lchild;
            swap(_oriroot->colored, _newroot->colored);
            _newroot->parent = _oriroot->parent;
            if (_newroot->parent != nullptr) {
                if (_oriroot == _oriroot->parent->rchild)
                    _oriroot->parent->rchild = _newroot;
                else
                    _oriroot->parent->lchild = _newroot;
            }
            _oriroot->parent = _newroot;
            _oriroot->lchild = _newroot->rchild;
            if (_oriroot->lchild != nullptr)
                _oriroot->lchild->parent = _oriroot;
            _newroot->rchild = _oriroot;
            return rt->parent;
        }
    return rt;
}

struct Node * fixup(struct Node *rt) {
    /**
     * @return `root` of the Whole Tree...
     */
    if (rt != nullptr) {
        if (rt->rchild != nullptr)
            if (rt->rchild->colored)
                rt = rotate(rt);
        if (rt->lchild != nullptr && rt->lchild->lchild != nullptr)
            if (rt->lchild->colored && rt->lchild->lchild->colored)
                rt = rotrev(rt);
        if (rt->lchild != nullptr && rt->rchild != nullptr)
            if (rt->lchild->colored && rt->rchild->colored)
                rt->flip();
        if (rt->parent != nullptr)
            return fixup(rt->parent);
        else
            rt->colored = false;
    }
    return rt;
}

inline
struct Node * append(struct Node **rt, int _value) {
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
        return fixup(psi);
    } else {
        // 根節點初始化為無色節點
        (*rt) = (struct Node *)malloc(sizeof(struct Node));
        (*rt)->__init__(_value, nullptr, false);
        return (*rt);
    }
}

inline
struct Node * moveleft(struct Node *rt) {
    if (rt != nullptr) {
        printf("(%d -> ", rt->val);
        rt->flip();
        if (rt->rchild != nullptr)
            if (rt->rchild->lchild != nullptr)
                if (rt->rchild->lchild->colored) {
                    rt->rchild = rotrev(rt->rchild);
                    rt = rotate(rt);
                    rt->flip();
                }
        printf("%d)\n", rt->val);
    }
    return rt;
}

int main(int argc, char *argv[]) {
    //freopen("./q1299-in03.txt", "r", stdin);
    //scanf("%d", &m);
    switch (2) {
    case 1:
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
        break;
    case 2: // Testing Function `moveleft` ...
        root = (struct Node *)malloc(sizeof(struct Node));
        root->__init__(128, nullptr, false);
        root->lchild = (struct Node *)malloc(sizeof(struct Node));
        root->lchild->__init__(39, root, true);
        root->lchild->lchild = (struct Node *)malloc(sizeof(struct Node));
        root->lchild->lchild->__init__(2, root->lchild, false);
        root->lchild->lchild->lchild = (struct Node *)malloc(sizeof(struct Node));
        root->lchild->lchild->lchild->__init__(1, root->lchild->lchild, false);
        root->lchild->lchild->rchild = (struct Node *)malloc(sizeof(struct Node));
        root->lchild->lchild->rchild->__init__(3, root->lchild->lchild, false);
        root->lchild->rchild = (struct Node *)malloc(sizeof(struct Node));
        root->lchild->rchild->__init__(56, root->lchild, false);
        root->lchild->rchild->lchild = (struct Node *)malloc(sizeof(struct Node));
        root->lchild->rchild->lchild->__init__(49, root->lchild->rchild, true); // which is the exactly `rt->rchild->lchild`, leading to 2 different conditions ...
        root->lchild->rchild->lchild->lchild = (struct Node *)malloc(sizeof(struct Node));
        root->lchild->rchild->lchild->lchild->__init__(48, root->lchild->rchild->lchild, false);
        root->lchild->rchild->lchild->rchild = (struct Node *)malloc(sizeof(struct Node));
        root->lchild->rchild->lchild->rchild->__init__(50, root->lchild->rchild->lchild, false);
        root->lchild->rchild->rchild = (struct Node *)malloc(sizeof(struct Node));
        root->lchild->rchild->rchild->__init__(57, root->lchild->rchild, false);
        root->printall();
        //root->lchild = moveleft(root->lchild);
        popmin(root);
        root->printall();
        break;
    default:
        for (int k = 0; k != m; ++k) {
            scanf("%d", &curval);
            root = append(&root, curval);
        }
        root->printall();
        popmin(root);
    }
    return 0;
}

/*
# Input:
3
8 3 9
# Visulization:
      8
     / \
    3   9

***

# Input:
3
8 1 3
# Visualization:
      8
     /
    1
     \
      3

***

# Input:
6
9 2 1 4 3 8
# Visualization:
        9                       9
       /                       /
      2                       4
     / \\    rotate(l)=>    // \
    1    4                 2    8
        / \               / \
       3   8             1   3

***

# Input:
5
8 2 1 3 9
6
8 2 1 4 3 9
# Visualization:
        8
       / \
      2   9
     / \
    1   4
      (3)
*/
