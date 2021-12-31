#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
using namespace __gnu_cxx;

int m;
bool typ;

map <char, int> diction;
map <int, char> invdict;

char cur_char, input_str[256];

struct numword {
    vector <int> vals;
} cur_word;

bool wordcmp0(struct numword psi, struct numword phi) {
    for (int idx = 0; idx < min(psi.vals.size(), phi.vals.size()); ++idx)
        if (psi.vals[idx] != phi.vals[idx])
            return psi.vals[idx] > phi.vals[idx];
    return psi.vals.size() > phi.vals.size();
}

bool wordcmp1(struct numword psi, struct numword phi) {
    for (int idx = 0; idx < min(psi.vals.size(), phi.vals.size()); ++idx)
        if (psi.vals[idx] != phi.vals[idx])
            return psi.vals[idx] < phi.vals[idx];
    return psi.vals.size() < phi.vals.size();
}

vector <struct numword> words;

int main(int argc, char *argv[]) {
    
    for (int idx = 0; idx < 26; ++idx) {
        cur_char = getchar();
        diction.insert(pair <char, int> (cur_char, idx + 1));
        invdict.insert(pair <int, char> (idx + 1, cur_char));
    }
    
    scanf("%d", &m);
    
    for (int idx = 0; idx < m; ++idx) {
        scanf("%s", input_str);
        for (int strbit = 0; strbit < strlen(input_str); ++strbit)
            cur_word.vals.push_back(diction[input_str[strbit]]);
        words.push_back(cur_word);
        cur_word.vals.clear();
    }
    
    scanf("%d", &typ);

    if (typ)
        sort(words.begin(), words.end(), wordcmp1);
    else
        sort(words.begin(), words.end(), wordcmp0);

    for (int idx = 0; idx < m; ++idx) {
        for (int strbit = 0; strbit < words[idx].vals.size(); ++strbit)
            putchar(invdict[ words[idx].vals[strbit] ]);
            //printf("%d, ", words[idx].vals[strbit]);
        putchar('\n');
    }

    return 0;
}
