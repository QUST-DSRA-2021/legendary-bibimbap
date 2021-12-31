#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace __gnu_cxx;

int m, n, cur_id, cur_score, least_score, idx;

struct player {
    int id, score;
    /*bool operator < (const player & that) {
        return (score == that.score) ? (id < that.id) : (score > that.score);
    }*/
} cur_player;

bool player_compare(struct player a, struct player b) {
    return (a.score == b.score) ? (a.id < b.id) : (a.score > b.score);
}

vector <player> players;

int main(int argc, char *argv[]) {
    scanf("%d %d", &m, &n);
    for (idx = 0; idx < m; ++idx) {
        scanf("%d %d", &cur_id, &cur_score);
        cur_player.id = cur_id;
        cur_player.score = cur_score;
        players.push_back(cur_player);
    }
    sort(players.begin(), players.end(), player_compare);
    for (idx = 0; players[idx].score >= players[floor(n * 1.5) - 1].score; ++idx)
        continue;
    printf("%d %d\n", players[idx - 1].score, idx);
    for (int k = 0; players[k].score >= players[idx - 1].score; ++k)
        printf("%d %d\n", players[k].id, players[k].score);
    return 0;
}
