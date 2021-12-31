#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

int m, cur, x;
vector <int> vec;
vector <int> :: iterator itr;

int main(int argc, char *argv[]) {
    freopen("./q2101-in.txt", "r", stdin);
    scanf("%d", &m);
    for (int k = 0; k < m; ++k) {
        scanf("%d", &cur);
        vec.push_back(cur);
    }
    scanf("%d", &x);
    itr = find(vec.begin(), vec.end(), x);
    if (itr != vec.end())
        printf("%d\n", itr - vec.begin() + 1);
    else
        printf("0\n");
    return 0;
}
