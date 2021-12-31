#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
using namespace __gnu_cxx;

const int HASHING_BASE = 131,
        HASHING_MODULO = 19260817;

inline int strhash(char *st) {
    int res = 0;
    for (char * itr = st; *itr != '\0'; ++itr)
        res = (res * HASHING_BASE + int(*itr - 'A')) % HASHING_MODULO;
    return res;
}

int main(int argc, char *argv[]) {
    printf("%d\n", strhash("MIKU"));
    printf("%d\n", strhash("AYUMU"));
    printf("%d\n", strhash("TIANYI"));
    return 0;
}
