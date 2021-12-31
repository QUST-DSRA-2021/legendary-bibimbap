#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

int q = 1;
char ch;
vector <int> arr16, arr8;

int main(int argc, char *argv[]) {
    while (ch != EOF && ch != '\n') {
        ch = getchar();
        arr16.push_back(isdigit(ch) ? (ch - '0') : (ch - 'A' + 10));
    }
    for (auto itr = arr16.begin(); itr != arr16.end(); )
        printf("%d, ", *(itr++));
    putchar('\n');
    return 0;
}
