#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
using namespace __gnu_cxx;

int val, stk[111], top = 0;
char st[10];

int main(int argc, char *argv[]) {
    freopen("./q1136-in.txt", "r", stdin);
    while (~scanf("%s", st)) {
        if (isdigit(st[0])) {
            val = 0;
            for (int k = 0; k < strlen(st); ++k)
                val = val * 10 + st[k] - '0';
            stk[top++] = val;
        } else {
            if (st[0] == '+') {
                stk[top - 2] = stk[top - 2] + stk[top - 1];
                stk[--top] = 0;
            } else if (st[0] == '-') {
                stk[top - 2] = stk[top - 2] - stk[top - 1];
                stk[--top] = 0;
            } else {
                stk[top - 2] = stk[top - 2] * stk[top - 1];
                stk[--top] = 0;
            }
        }
    }
    printf("%d\n", stk[top - 1]);
    return 0;
}

