#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

int m, inval;
vector <int> arr;

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    for (int idx = 0; idx < m; ++idx) {
        scanf("%d", &inval);
        arr.push_back(inval);
    }
    sort(arr.begin(), arr.end());
    for (vector <int> :: iterator iter = arr.begin(); iter != arr.end(); ++iter)
        printf("%d\n", *iter);
    return 0;
}
