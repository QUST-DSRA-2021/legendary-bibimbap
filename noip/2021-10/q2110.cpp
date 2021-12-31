#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

int m, n, cur, target;
vector <int> arr;

int main(int argc, char *argv[]) {
    scanf("%d %d", &m, &n);
    for (int k = 0; k < m; ++k)
        for (int l = 0; l < n; ++l) {
            scanf("%d", &cur);
            arr.push_back(cur);
        }
    scanf("%d", &target);
    auto itr = find(arr.begin(), arr.end(), target);
    int res = itr - arr.begin();
    if (res < m * n)
        printf("%d %d\n", res / n, res % n);
    else
        printf("NOT FOUND\n");
    return 0;
}
