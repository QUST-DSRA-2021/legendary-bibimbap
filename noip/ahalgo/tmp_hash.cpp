#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

const int MOD = 192608173;
const int BASE = 233;

int hsh(string s) {
    int res = 0;
    for (int k = 0; k != s.size(); ++k)
        res = (res * BASE + (int)s[k]) % MOD;
    return res;
}

int m, res = 1;
vector <int> nums;
string s;

int main() {
    freopen("./p3370-in.txt", "r", stdin);
    scanf("%d", &m);

    for(int k = 0; k != m; ++k) {
        cin >> s;
        nums.push_back(hsh(s));
    }

    sort(nums.begin(), nums.end());

    for (auto itr = nums.begin() + 1; itr != nums.end(); ++itr)
        if (*itr != *(itr - 1))
            ++res;

    printf("%d\n", res);
    return 0;
}

