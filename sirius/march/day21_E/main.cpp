#include <bits/stdc++.h>

using namespace std;


const int MY_TURN = 1;
const int ENEMY_TURN = -1;
map<int, char> symbol = {{MY_TURN, 'x'}, {ENEMY_TURN, 'o'}};
struct ReturnState{
    int x, y, score;

    bool operator<(const ReturnState &rhs) const {
        return tie(x, y, score) < tie(rhs.x, rhs.y, rhs.score);
    }
};
using fld = vector<string>;

bool check(fld &a, char c){
    for (int i = 0; i < 3; ++i) {
        int sum = 0;
        for (int j = 0; j < 3; ++j)
            sum += (a[i][j] == c);
        if (sum == 3)
            return true;
        sum = 0;
        for (int j = 0; j < 3; ++j)
            sum += (a[j][i] == c);
        if (sum == 3)
            return true;
    }
    int sum = 0;
    for (int i = 0; i < 3; i++)
        sum += (a[i][i] == c);
    if (sum == 3)
        return true;
    sum = 0;
    int x = 0;
    int y = 2;
    for (int i = 0; i < 3; i++)
        sum += (a[x++][y--] == c);
    return sum == 3;
}
int getScore(fld &state){
    if (check(state, symbol[MY_TURN]))
        return 1;
    if (check(state, symbol[ENEMY_TURN]))
        return -1;
    return 0;
}
ReturnState minimax(fld &state, int turn, int depth){
    ReturnState ret_state = {-1, -1, (int) 1e9};
    if (turn == ENEMY_TURN)
        ret_state.score *= -1;

    if (depth == 0 || check(state, symbol[ENEMY_TURN]) || check(state, symbol[MY_TURN]))
        return {-1, -1,getScore(state)};

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (state[i][j] != '.')
                continue;
            state[i][j] = symbol[turn];
            auto sc = minimax(state, -turn, depth - 1);
        }
    }
}