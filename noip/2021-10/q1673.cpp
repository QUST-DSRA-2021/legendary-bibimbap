#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

int update(int val, int times) {
    int res = 0;
    while (val) {
        int newbit = 1;
        for (int k = 0; k < times; ++k)
            newbit *= val % 10;
        res += newbit;
        val /= 10;
    }
    return res;
}

int m, cur;
vector <int> arr, gen;

int main(int argc, char *argv[]) {
    freopen("./q1673-in.txt", "r", stdin);
    scanf("%d", &m);
    while (~scanf("%d", &cur))
        arr.push_back(cur);
    for (int k = 0; k < m; ++k) {
        for (int x : arr)
            gen.push_back(update(x, k + 2));
        sort(gen.begin(), gen.end());

        /*
        printf("Generated Array: ");
        for (int x : gen)
            printf("%d, ", x);
        putchar('\n');
        */

        for (auto l = arr.begin(); l != arr.end(); ) {
            bool flg = binary_search(gen.begin(), gen.end(), *l);

            //printf("%d exists in generated array: %d\n", *l, flg);

            if (flg)
                arr.erase(l);
            else
                ++l;
        }
        gen.clear();

        //putchar('\n');
    }
    sort(arr.begin(), arr.end());
    for (int x : arr)
        printf("%d ", x);
    putchar('\n');
    return 0;
}
