#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
using namespace __gnu_cxx;

int m_bits;
int bitseq[20], seqlen = 0, x;
bool flag = true;

void printinbit(int val) {
    if (val) {
        printinbit(val / m_bits);
        putchar((val % m_bits < 10) ? char(val % m_bits + '0') : char(val % m_bits - 10 + 'A'));
    }
}

void judge_palindrome(int val) {
    for (int l = 0; l < 20; ++l)
        bitseq[l] = 0;
    seqlen = 0;
    x = val * val;
    flag = true;

    while (x) {
        bitseq[seqlen++] = x % m_bits;
        x /= m_bits;
    }

    for (int l = 0; l < (seqlen >> 1); ++l)
        if (bitseq[l] != bitseq[seqlen - l - 1])
            flag = false;

    if (flag) {
        printinbit(val);
        putchar(' ');
        printinbit(val * val);
        putchar('\n');
    }

    return;
}

int main(int argc, char *argv[]) {
    scanf("%d", &m_bits);
    for (int k = 1; k < 301; ++k)
        judge_palindrome(k);
    return 0;
}
