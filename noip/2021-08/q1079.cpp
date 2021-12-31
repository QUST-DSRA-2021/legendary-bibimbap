#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

int m;

struct pokercard {
    char suit;
    int val;
} cur_card;

char cur_suit;
int cur_val;

vector <struct pokercard> pokers, pokers1, pokers2;

char testack[11][36];
int judgelen[11];

bool flag = true;

void bubblesort(int arlength) {
    if (arlength) {
        for (int idx = 0; idx < arlength - 1; ++idx)
            if (pokers1[idx].val > pokers1[idx + 1].val)
                swap(pokers1[idx], pokers1[idx + 1]);
        return bubblesort(arlength - 1);
    }
}

void selectsort(int starter) {
    if ((m - 1) - starter) {
        int idx_min = starter;
        for (int idx = starter; idx < m; ++idx)
            idx_min = (pokers2[idx].val < pokers2[idx_min].val) ? idx : idx_min;
        if (starter < idx_min)
            swap(pokers2[starter], pokers2[idx_min]);
        return selectsort(starter + 1);
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &m);
    for (int idx = 0; idx < m; ++idx) {
        getchar();
        scanf("%c%d", &cur_suit, &cur_val);
        cur_card.suit = cur_suit;
        cur_card.val = cur_val;
        pokers.push_back(cur_card);
    }

    pokers1.assign(pokers.begin(), pokers.end());
    pokers2.assign(pokers.begin(), pokers.end());

    bubblesort(m);
    for (int idx = 0; idx < m; ++idx)
        printf("%c%d ", pokers1[idx].suit, pokers1[idx].val);
    printf("\nStable\n");

    selectsort(0);
    for (int idx = 0; idx < m; ++idx)
        printf("%c%d ", pokers2[idx].suit, pokers2[idx].val);

    // To Judge the Result of Selection Sort STABLE or not...
    for (int idx = 0; idx < m; ++idx) {
        cur_suit = pokers[idx].suit;
        cur_val = pokers[idx].val;
        testack[cur_val][ judgelen[cur_val]++ ] = cur_suit;
    }
    for (int idx = m - 1; idx >= 0; --idx) {
        cur_suit = pokers2[idx].suit;
        cur_val = pokers2[idx].val;
        if (testack[cur_val][ judgelen[cur_val] - 1 ] == cur_suit)
            --judgelen[cur_val];
    }

    for (int idx = 1; idx < 10; ++idx) {
        //printf("%d, ", judgelen[idx]);
        if (judgelen[idx])
            flag = false;
    }

    if (flag)
        printf("\nStable\n");
    else
        printf("\nNot stable\n");

    return 0;
}
