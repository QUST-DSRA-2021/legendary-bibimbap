#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m;

struct ip_address {
    int val[4];
    void readip() {
        scanf("%d.%d.%d.%d", &val[0], &val[1], &val[2], &val[3]);
    }
    void printip() {
        for (int l = 0; l < 4; ++l)
            printf("%d, ", val[l]);
        putchar('\n');
    }
} localip, submask, newip;

int main(int argc, char *argv[]) {
    freopen("./q1679-in.txt", "r", stdin);
    localip.readip();
    localip.printip();
    submask.readip();
    submask.printip();
    scanf("%d", &m);
    for (int k = 0; k < m; ++k) {
        newip.readip();
        newip.printip();
        if (((newip.val[0] & submask.val[0]) == (localip.val[0] & submask.val[0]))
            && ((newip.val[1] & submask.val[1]) == (localip.val[1] & submask.val[1]))
            && ((newip.val[2] & submask.val[2]) == (localip.val[2] & submask.val[2]))
            && ((newip.val[3] & submask.val[3]) == (localip.val[3] & submask.val[3])))
            printf("INNER\n");
        else
            printf("OUTER\n");
    }
    return 0;
}
