#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

int m, cur, stk[1000], top = 0, idx = 1;

/**
 * 题意分析
 * 在中转站C中，车厢符合后进先出的原则，因此是一个栈。
 * 假设我们已经处理了前 k-1 节从B方向驶出的车厢，我们现在要让 a_k 驶出。
 * 若 a_k 不在车站C中，我们就让若干车厢从A方向驶入车站C，直到 a_k 驶入，再将它从B方向驶出；
 * 若 a_k 在车站C中，如果它是车站C中停在最前面的，则将它从B方向驶出，否则原问题无解。
 */

int main(int argc, char *argv[]) {
    freopen("./q2053-in.txt", "r", stdin);
    scanf("%d", &m);
    for (int k = 0; k < m; ++k) {
        scanf("%d", &cur);
        while (idx <= cur)
            stk[top++] = (idx++);
        if (stk[top - 1] == cur)
            stk[--top] = 0;
        else {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
