#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

int m, q, lq = 0, cur, res = 0;
pair <vector <int> :: iterator, vector <int> :: iterator> eqres;
vector <int> arr;

int main(int argc, char *argv[]) {
    freopen("./q1107-in.txt", "r", stdin);
    scanf("%d", &m);
    for (int k = 0; k < m; ++k) {
        scanf("%d", &cur);
        arr.push_back(cur);
    }
    eqres.first = arr.end();
    eqres.second = arr.begin();
    scanf("%d", &q);
    for (int k = 0; k < q; ++k) {
        scanf("%d", &cur);
        eqres = (cur < lq) ? equal_range(arr.begin(), eqres.first, cur) : equal_range(eqres.second, arr.end(), cur);
        res += int(eqres.second - eqres.first);
        lq = cur;
    }
    printf("%d\n", res);
    return 0;
}
