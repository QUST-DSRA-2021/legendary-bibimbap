#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

struct Tup {
    int u, w, t;
    char d[14], s[25];
    //Tup(int _u, int _w, int _t) : u(_u), w(_w), t(_t) {}
    void init(int _u, int _w, int _t, char *_d, char *_s) {
        u = _u;
        w = _w;
        t = _t;
        strcpy(d, _d);
        strcpy(s, _s);
        return;
    }
} tuples[100001];
bool tuplecmp(struct Tup psi, struct Tup phi) {
    if (psi.u != phi.u)
        return psi.u < phi.u;
    else if (psi.w != phi.w)
        return psi.w < phi.w;
    else if (psi.t != phi.t)
        return psi.t < phi.t;
    else if (strcmp(psi.d, phi.d)) {
        return (strlen(psi.d) == strlen(phi.d)) ? (strcmp(psi.d, phi.d) < 0) : (strlen(psi.d) < strlen(phi.d));
    }
    else
        return strcmp(psi.s, phi.s) < 0;
}

//vector <Tup> tuples;

int m, cur = 0,
    u0, w0;
char t0, d0[20], s0[10];

int main(int argc, char *argv[]) {
    freopen("./q1278-in.txt", "r", stdin);

    scanf("%d", &m);

    for (int k = 0; k < m; ++k) {
        scanf("%d %d %c %s %s", &u0, &w0, &t0, d0, s0);
        //newtuple.setdate(d0);
        //newtuple.setname(s0);
        //tuples.push_back(newtuple);
        tuples[cur++].init(u0, w0, t0, d0, s0);
    }

    //sort(tuples.begin(), tuples.end(), tuplecmp);
    sort(tuples, tuples + m, tuplecmp);

    for (int k = 0; k < m; ++k)
        printf("%d %d %c %s %s\n", tuples[k].u, tuples[k].w, char(tuples[k].t), tuples[k].d, tuples[k].s);

    return 0;
}
