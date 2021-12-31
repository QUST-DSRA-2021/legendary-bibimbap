#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

const int GAPS[] = { 1, 4, 13, 40, 121, 364, 1093, 3280, 9841, 29524, 88573, 265720, 797161 };
int m, cur_input, cnt = 0, max_elem = -1;
vector <int> arr, gaps;

void insertion_sort(int gap) {
    for (int k = gap; k < m; ++k) {
        int u = arr[k], l = k - gap;
        while (l >= 0 && arr[l] > u) {
            swap(arr[l + gap], arr[l]);
            l -= gap;
            ++cnt;
        }
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    for (int idx = 0; idx < m; ++idx) {
        scanf("%d", &cur_input);
        arr.push_back(cur_input);
    }
    for (int idx = 12; idx >= 0; --idx)
        if (GAPS[idx] <= m)
            gaps.push_back(GAPS[idx]);
    for (int idx = 0; idx < gaps.size(); ++idx)
        insertion_sort(gaps[idx]);

    printf("%d\n", int(gaps.size()));
    for (vector <int> :: iterator iter = gaps.begin(); iter != gaps.end(); ++iter)
        printf("%d ", *iter);
    putchar('\n');

    printf("%d\n", cnt);

    for (vector <int> :: iterator iter = arr.begin(); iter != arr.end(); ++iter)
        printf("%d\n", *iter);
    
    return 0;
}
