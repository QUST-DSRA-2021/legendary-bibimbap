#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
using namespace __gnu_cxx;

struct Edge {
    int weight;
    struct Node *ender;
    struct Edge *next;
};

struct Node {
    int val;
    struct Edge *edges;
    // set for dfs & bfs
    bool visited;
    int time_in, time_out, dist;
} *graphnodes[3965];

inline struct Node *newnode(int _val) {
    struct Node * _res = (struct Node *)malloc(sizeof(struct Node));
    _res->val = _val;
    _res->edges = (struct Edge *)malloc(sizeof(struct Edge));
    _res->edges->weight = -1;
    _res->edges->ender = nullptr;
    _res->edges->next = nullptr;
    // set for dfs & bfs
    _res->visited = false;
    _res->time_in = 0;
    _res->time_out = 0;
    _res->dist = -1;
    return _res;
}

inline struct Edge *newedge(int _ed, int _w) {
    struct Edge * _res = (struct Edge *)malloc(sizeof(struct Edge));
    _res->weight = _w;
    _res->ender = graphnodes[_ed];
    _res->next = nullptr;
    return _res;
}

inline void appendedge(struct Node *nd, int _ed, int _w) {
    struct Edge * _newedge = newedge(_ed, _w),
                * v = nd->edges;
    while (v->next != nullptr) {
        if (v->next->ender->val < _newedge->ender->val)
            v = v->next;
        else
            break;
    }
    _newedge->next = v->next;
    v->next = _newedge;
}

bool judge_connectivity(struct Node *psi, struct Node *phi) {
    if (psi != phi) {
        bool _res = false;
        psi->visited = true;
        for (struct Edge * v = psi->edges; v != nullptr; v = v->next)
            if (v->ender != nullptr)
                if (!v->ender->visited)
                    if (judge_connectivity(v->ender, phi))
                        _res = true;
        psi->visited = false;
        return _res;
    } else
        return true;
}

int m, n, s, t, q;

int main(int argc, char *argv[]) {
    scanf("%d %d", &m, &n);
    for (int k = 0; k != m; ++k)
        graphnodes[k] = newnode(k);
    for (int k = 0; k != n; ++k) {
        scanf("%d %d", &s, &t);
        appendedge(graphnodes[s], t, 1);
        appendedge(graphnodes[t], s, 1);
    }
    scanf("%d", &q);
    for (int k = 0; k != q; ++k) {
        scanf("%d %d", &s, &t);
        if (judge_connectivity(graphnodes[s], graphnodes[t]))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}

