#include <cstdio>
#include <cstdlib>
#include <cstring>

int m, *arr, cur, *itr;

int main(int argc, char *argv[]) {
    freopen("./arrdata.txt", "r", stdin);
    scanf("%d", &m);
    arr = (int *)calloc(m, sizeof(int));
    itr = arr;
    for (int k = 0; k != m; ++k)
        scanf("%d", itr++);
    itr = arr;
    for (int k = 0; k != m; ++k)
        printf("%d, ", *(itr++));
    putchar('\n');
    return 0;
}
