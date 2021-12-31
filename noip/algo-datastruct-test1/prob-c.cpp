#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, n, z[10001], task[101], res = 0;

int main(int argc, char *argv[]) {
    scanf("%d %d", &m, &n);
    for (int k = 0; k < m; ++k)
        scanf("%d", &z[k]);
    if (m <= n) {
        int curmax = 0;
        for (int k = 0; k < m; ++k)
            if (z[k] > curmax)
                curmax = z[k];
        printf("%d\n", curmax);
    } else {
        // 初始化: n个窗口为人类1~n排队
        for (int k = 0; k < n; ++k)
            task[k] = z[k];
        // 用于标记下一个需要排队的人类的指针
        int nextone = n;
        for (res = 0; ; ++res) {
            bool flag = false;
            for (int k = 0; k < n; ++k) {
                if (task[k] > 0)
                    --task[k];
                if (!task[k] && nextone != m)
                    task[k] += z[nextone++];
                if (task[k])
                    flag = true;
            }
            if (!flag)
                break;
        }
        printf("%d\n", ++res);
    }
    return 0;
}
