#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

int m, s, flag = 2,
    bitseq[20], seqlen = 0,
    x = 0, ret = true;

bool judge_in_base(int val, int m_base) {
    for (int r = 0; r < 20; ++r)
        bitseq[r] = 0;
    seqlen = 0;
    x = val;
    ret = true;
    while (x) {
        bitseq[seqlen++] = x % m_base;
        x /= m_base;
    }
    for (int r = 0; r < (seqlen >> 1); ++r)
        if (bitseq[r] != bitseq[seqlen - r - 1])
            ret = false;
    return ret;
}

bool judge_palindrome(int val) {
    flag = 2;
    for (int l = 2; l < 11 && flag; ++l)
        flag -= judge_in_base(val, l);
    return !flag;
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &m, &s);

    for (int k = s + 1; m; ++k)
        if (judge_palindrome(k)) {
            printf("%d\n", k);
            --m;
        }

    return 0;
}
