#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iostream>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

char st1[200], st2[200];
vector <int> res;
int len1, len2;
bool flag;

int main(int argc, char *argv[]) {
    scanf("%s\n%s", st1, st2);
    len1 = strlen(st1);
    len2 = strlen(st2);

    if (len1 > len2)
        flag = false;
    else if (len1 < len2)
        flag = true;
    else
        if (strcmp(st1, st2) > 0)
            flag = false;
        else if (strcmp(st1, st2) < 0)
            flag = true;
        else {
            printf("0\n");
            return 0;
        }

    if (flag) {
        for (int k = 0; k < len1; ++k)
            res.push_back(st2[len2 - k - 1] - st1[len1 - k - 1]);
        for (int k = 0; k < (len2 - len1); ++k)
            res.push_back(st2[len2 - len1 - k - 1] - '0');
    } else {
        for (int k = 0; k < len2; ++k)
            res.push_back(st1[len1 - k - 1] - st2[len2 - k - 1]);
        for (int k = 0; k < (len1 - len2); ++k)
            res.push_back(st1[len1 - len2 - k - 1] - '0');
    }

    for (auto itr = res.begin(); itr != res.end(); ++itr)
        printf("%d, ", *itr);
    putchar('\n');

    for (auto itr = res.begin(); itr != res.end(); ++itr)
        while (*itr < 0) {
            *itr += 10;
            *(itr + 1) -= 1;
        }

    for (auto itr = res.begin(); itr != res.end(); ++itr)
        printf("%d, ", *itr);
    putchar('\n');

    if (flag)
        putchar('-');
    auto q = res.end() - 1;
    while (!(*q))
        --q;
    for (q; q != res.begin(); --q)
        putchar(*q + '0');
    putchar(*q + '0');
    putchar('\n');

    return 0;
}

