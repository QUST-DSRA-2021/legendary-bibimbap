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

int m, q, r, s, current_time = 0, num_visited = 0;

queue <struct Node *> que;

void recurse(struct Node *nd) {
    nd->time_in = ++current_time;
    nd->visited = true;
    for (struct Edge * v = nd->edges->next; v != nullptr; v = v->next)
        if (v->ender != nullptr)
            if (!v->ender->visited)
                recurse(v->ender);
    nd->time_out = ++current_time;
}

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    for (int k = 0; k != m; ++k)
        graphnodes[k] = newnode(k);
    for (int k = 0; k != m; ++k) {
        scanf("%d %d", &r, &q); --r;
        for (int l = 0; l != q; ++l) {
            scanf("%d", &s); --s;
            appendedge(graphnodes[r], s, 1);
        }
    }
    if (true) {
        for (int k = 0; k != m; ++k)
            if (!graphnodes[k]->visited)
                recurse(graphnodes[k]);
        for (int k = 0; k != m; ++k)
            printf("%d %d %d\n", k + 1, graphnodes[k]->time_in, graphnodes[k]->time_out);
    } else {
        graphnodes[0]->visited = true;
        graphnodes[0]->dist = 0;
        que.push(graphnodes[0]);
        while (!que.empty()) {
            struct Node * v = que.front();
            for (struct Edge * u = v->edges->next; u != nullptr; u = u->next)
                if (u->ender != nullptr)
                    if (!u->ender->visited) {
                        u->ender->visited = true;
                        u->ender->dist = v->dist + 1;
                        que.push(u->ender);
                    }
            que.pop();
        }
        for (int k = 0; k != m; ++k)
            printf("%d %d\n", k + 1, graphnodes[k]->dist);
    }
    return 0;
}
