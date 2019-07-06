#include <bits/stdc++.h>
#include <ostream>

using namespace std;
const char PLAYER = '+';
const char ENEMY = 'x';
const char WALL = '#';
const char FREE = '.';


struct Position {
    int x, y;

    Position(int x, int y) : x(x), y(y) {}

    Position() {}

    Position operator+(const Position &oth) const {
        return {x + oth.x, y + oth.y};
    }

    friend ostream &operator<<(ostream &os, const Position &position) {
        os << position.x << " " << position.y;
        return os;
    }
};

vector<Position> deltas = {{0,  +1},
                           {0,  -1},
                           {+1, 0},
                           {-1, 0}};

struct Field {
    vector<vector<char>> field;
    int n, m;

    bool inField(const Position &pos) const {
        return pos.x >= 0 && pos.y >= 0 && pos.x < n && pos.y < m;
    }

    bool isFree(const Position &pos) const {
        int x = pos.x;
        int y = pos.y;
        return inField(pos) && field[x][y] == FREE;
    }

    char operator[](const Position &pos) const {
        return field[pos.x][pos.y];
    }

    char &operator[](const Position &pos) {
        return field[pos.x][pos.y];
    }

    vector<char> operator[](const int &x) const {
        return field[x];
    }

    vector<char> &operator[](const int &x) {
        return field[x];
    }

    friend istream &operator>>(istream &is, Field &fld) {
        is >> fld.n >> fld.m;
        fld.field.assign(fld.n, vector<char>(fld.m));
        for (int i = 0; i < fld.n; i++)
            for (int j = 0; j < fld.m; j++)
                cin >> fld[i][j];
        return is;
    }
};

Position get_move(const Field &field) {
    Position player, enemy;

    for (int i = 0; i < field.n; i++)
        for (int j = 0; j < field.m; j++) {
            if (field[i][j] == PLAYER)
                player = Position(i, j);
            if (field[i][j] == ENEMY)
                enemy = Position(i, j);
        }
    vector<int> possible_choices;
    for (int choice = 0; choice < 4; choice++) {
        Position nxt = player + deltas[choice];
        if (field.isFree(nxt))
            possible_choices.push_back(choice);
    }
    random_shuffle(possible_choices.begin(), possible_choices.end());
    return player + deltas[possible_choices[0]];
}

int main() {
    srand(time(0));
    while (true) {
        Field field;
        cin >> field;
        cout << get_move(field) << '\n';
    }

}