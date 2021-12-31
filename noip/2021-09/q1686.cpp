#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

int m;

int gcd(int v, int u) {
    if (v < u)
        return gcd(u, v);
    return u ? gcd(u, v % u) : v;
}

struct Fraction {
    int numer, deno;
};

bool fracmp(struct Fraction a, struct Fraction b) {
    return (a.numer * b.deno) < (b.numer * a.deno);
}

vector <struct Fraction> fraclist;

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    for (int k = 0; k < m; ++k)
        for (int l = 1; l < k + 1; ++l) {
            if (gcd(l, k + 1) == 1) {
                struct Fraction newfrac;
                newfrac.numer = l;
                newfrac.deno = k + 1;
                fraclist.push_back(newfrac);
            }
        }
    sort(fraclist.begin(), fraclist.end(), fracmp);
    printf("0/1\n");
    for (auto itr = fraclist.begin(); itr != fraclist.end(); ++itr)
        printf("%d/%d\n", (*itr).numer, (*itr).deno);
    printf("1/1\n");
    return 0;
}
