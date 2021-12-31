#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

int m, cur, sum = 0;
vector <int> vec;

int main(int argc, char *argv[]) {
    freopen("./q2095-in.txt", "r", stdin);
    scanf("%d", &m);
    for (int idx = 0; idx < m; ++idx) {
        scanf("%d", &cur);
        vec.push_back(cur);
        sum += cur;
    }
    sort(vec.begin(), vec.end());
    printf("%d\n", m - (upper_bound(vec.begin(), vec.end(), sum / m) - vec.begin()));
    return 0;
}
