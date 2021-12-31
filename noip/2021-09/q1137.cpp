#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int volume_0, concen_0, m, cur_volume, cur_concen, stk_volume[10000], stktop = 0;
char cur_opt;
float stk_concen[10000];

int main(int argc, char *argv[]) {
    freopen("./q1137-in.txt", "r", stdin);

    scanf("%d %d", &volume_0, &concen_0);

    stk_volume[stktop] = volume_0;
    stk_concen[stktop] = concen_0 * 1.;
    ++stktop;

    scanf("%d", &m);
    getchar();

    for (int k = 0; k < m; ++k) {
        scanf("%c", &cur_opt);

        if (cur_opt == 'Z') {
            if (stktop > 1) {
                --stktop;
                stk_volume[stktop] = 0;
                stk_concen[stktop] = 0.;
            }
        } else {
            getchar();
            scanf("%d %d", &cur_volume, &cur_concen);

            stk_volume[stktop] = stk_volume[stktop - 1] + cur_volume;
            stk_concen[stktop] = (stk_concen[stktop - 1] * stk_volume[stktop - 1] + cur_concen * cur_volume * 1.) / stk_volume[stktop];
            ++stktop;
        }

        getchar();
        printf("%d %.5f\n", stk_volume[stktop - 1], stk_concen[stktop - 1]);
    }

    return 0;
}
