#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

int m, l;
vector <int> arr;

int main(int argc, char *argv[]) {
    scanf("%d %d", &m, &l);
    for (int idx = 0; idx < m; ++idx) {
        int current_input;
        scanf("%d", &current_input);
        arr.push_back(current_input);
    }
    sort(arr.begin(), arr.end());
    vector <int> :: iterator uniq_ender = unique(arr.begin(), arr.end());
    arr.erase(uniq_ender, arr.end());
    if (l > arr.size())
        printf("NO RESULT\n");
    else
        printf("%d\n", arr[l - 1]);
    return 0;
}
