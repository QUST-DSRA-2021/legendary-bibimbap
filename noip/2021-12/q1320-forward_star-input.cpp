#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

struct Edge
{
    int weight;
    struct Node *ender;
    struct Edge *next;
};

struct Node
{
    int val;
    struct Edge *edges;
} *graphnodes[3965];

void nodeinit(int _idx)
{
    graphnodes[_idx] = (struct Node *)malloc(sizeof(struct Node));
    graphnodes[_idx]->val = _idx;
    graphnodes[_idx]->edges = (struct Edge *)malloc(sizeof(struct Edge));
    graphnodes[_idx]->edges->weight = -1;
    graphnodes[_idx]->edges->ender = nullptr;
    graphnodes[_idx]->edges->next = nullptr;
}

struct Edge *newedge(int _ed, int _w)
{
    struct Edge * _res = (struct Edge *)malloc(sizeof(struct Edge));
    _res->weight = _w;
    _res->ender = graphnodes[_ed];
    _res->next = nullptr;
    return _res;
}

void appendedge(struct Node *nd, int _ed, int _w)
{
    struct Edge * _newedge = newedge(_ed, _w),
                * _q = nd->edges;
    while (_q->next != nullptr)
    {
        if (_q->next->ender->val <= _newedge->ender->val)
        {
            _q = _q->next;
        }
        else
        {
            break;
        }
    }
    _newedge->next = _q->next;
    _q->next = _newedge;
}

int m, q, r, s;

int main(int argc, char *argv[])
{
    scanf("%d", &m);
    for (int k = 0; k != m; ++k)
    {
        nodeinit(k);
    }
    for (int k = 0; k != m; ++k)
    {
        scanf("%d %d", &r, &q); --r;
        printf("%d %d", r, q);
        for (int l = 0; l != q; ++l)
        {
            scanf("%d", &s); --s;
            appendedge(graphnodes[r], s, 1);
            printf(" %d", s);
        }
        putchar('\n');
    }
    for (int k = 0; k != m; ++k)
    {
        printf("%d:", graphnodes[k]->val);
        for (struct Edge * itr = graphnodes[k]->edges->next; itr != nullptr; itr = itr->next)
        {
            printf(" %d", itr->ender->val);
        }
        putchar('\n');
    }
    return 0;
}
