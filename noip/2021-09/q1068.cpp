#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

char current_carid[8];
vector <int> vec, deltas;
int res = 2147483647;

int main(int argc, char *argv[]) {
    freopen("./q1068-in.txt", "r", stdin);

    while (~scanf("%s", current_carid)) {
        int newid = 0;
        for (int k = 2; k < 7; ++k)
            newid = newid * 36 + (isdigit(current_carid[k]) ? (current_carid[k] - '0') : (current_carid[k] - 'A' + 10));
        vec.push_back(newid);
    }

    sort(vec.begin(), vec.end());

    for (int k = 0; k < vec.size() - 1; ++k) {
        if ((vec[k + 1] - vec[k]) < res)
            res = vec[k + 1] - vec[k];
    }

    printf("%d\n", res);

    return 0;
}
