#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, arr[100], target;

bool find(int *q, int num_arr, int tgt) {
    int * itr = q;
    for (int k = 0; k < num_arr; ++k)
        if (*(itr++) == tgt)
            return true;
    return false;
}

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    int * itr = arr;
    for (int k = 0; k < m; ++k)
        scanf("%d", itr++);
    scanf("%d", &target);
    if (find(arr, m, target))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
