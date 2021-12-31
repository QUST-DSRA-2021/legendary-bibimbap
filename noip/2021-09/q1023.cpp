#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m;

int dp(int num_steps) {
    if (num_steps > 1)
        return dp(num_steps - 1) + dp(num_steps - 2);
    else
        return 1;
}

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    printf("%d\n", dp(m));
    return 0;
}
