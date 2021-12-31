#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, q, r, s;

struct Edge {
    int idx;
    int weight;
    struct Edge *next;
    void init(int _idx, int _w, struct Edge *_next) {
        idx = _idx;
        weight = _w;
        next = _next;
    }
    void append(int _idx, int _w) {
        struct Edge *_newedge = (struct Edge *)malloc(sizeof(struct Edge));
        _newedge->init(_idx, _w, next);
        next = _newedge;
    }
};
struct Node {
    int val;
    struct Edge *edge0;
    Node() : val(-1) {
        edge0 = (struct Edge *)malloc(sizeof(struct Edge));
        edge0->init(-1, -1, nullptr);
    }
    void append(int _idx, int _w) {
        struct Edge * _itr = edge0;
        while (_itr->next != nullptr) {
            if (_itr->next->idx < _idx)
                _itr = _itr->next;
            else
                break;
        }
        _itr->append(_idx, _w);
    }
    void printedges() {
        struct Edge * _itr = edge0;
        printf("Head");
        while (_itr != nullptr) {
            printf("->(%d, %d)", _itr->idx, _itr->weight);
            _itr = _itr->next;
        }
        printf("-> /\\ \n");
    }
    void printmatrow() {
        bool flag[100];
        for (int k = 0; k != m; ++k)
            flag[k] = false;
        struct Edge * _itr = edge0->next;
        while (_itr != nullptr) {
            flag[_itr->idx] = true;
            _itr = _itr->next;
        }
        for (int k = 0; k != m; ++k)
            printf("%d ", flag[k]);
        putchar('\n');
    }
} nodes[100];

int main(int argc, char *argv[]) {
    freopen("./q1320-in.txt", "r", stdin);
    scanf("%d", &m);
    for (int k = 0; k != m; ++k) {
        scanf("%d %d", &r, &q);
        nodes[--r].val = r + 1;
        for (int l = 0; l != q; ++l) {
            scanf("%d", &s);
            nodes[r].append(s - 1, 39);
        }
        nodes[r].printmatrow();
    }
    return 0;
}
