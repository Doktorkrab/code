#include <bits/stdc++.h>
#include <ostream>

using namespace std;
const char PLAYER = '+';
const char ENEMY = 'x';
const char WALL = '#';
const char FREE = '.';
const int MAX_DEPTH = 5;
const double CAN_MOVE = 1;
const double WIN = 1000;

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

    bool operator<(const Position &rhs) const {
        if (x < rhs.x)
            return true;
        if (rhs.x < x)
            return false;
        return y < rhs.y;
    }

    bool operator>(const Position &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Position &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Position &rhs) const {
        return !(*this < rhs);
    }

    int operator-(const Position &oth) const {
        return abs(x - oth.x) + abs(y - oth.y);
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

Position player, enemy;
Field field;

void precalc() {
    for (int i = 0; i < field.n; i++)
        for (int j = 0; j < field.m; j++) {
            if (field[i][j] == PLAYER)
                player = Position(i, j);
            if (field[i][j] == ENEMY)
                enemy = Position(i, j);
        }
}

int dfs(Position pos, const vector<vector<int>> &fld, vector<vector<int>> &colors, int color) {
    colors[pos.x][pos.y] = color;
    int sum = 1;
    for (auto delta : deltas) {
        Position newPos = delta + pos;
        if (newPos.x < 0 || newPos.y < 0 || newPos.x >= colors.size() || newPos.y >= colors[0].size())
            continue;
        if (colors[newPos.x][newPos.y] != -1)
            continue;
        if (fld[newPos.x][newPos.y] == -1)
            continue;
        sum += dfs(newPos, fld, colors, color);
    }
    return sum;
}

vector<vector<int>> bfs(const vector<vector<int>> &fld, Position start) {
    vector<vector<int>> dist(fld.size(), vector<int>(fld[0].size(), 1e9));
    vector<vector<int>> used(fld.size(), vector<int>(fld[0].size(), 0));

    deque<Position> q = {start};
    dist[start.x][start.y] = 0;
    while (!q.empty()) {
        auto top = q.front();
        q.pop_front();
        if (used[top.x][top.y])
            continue;
        used[top.x][top.y] = 1;
        for (auto delta : deltas) {
            auto newPos = top + delta;
            if (newPos.x < 0 || newPos.y < 0 || newPos.x >= fld.size() || newPos.y >= fld[0].size() ||
                fld[newPos.x][newPos.y] == -1)
                continue;
            if (used[newPos.x][newPos.y])
                continue;
            dist[newPos.x][newPos.y] = dist[top.x][top.y] + 1;
            q.push_back(newPos);
        }
    }
    return dist;
}

pair<int, int> bfs1(const vector<vector<int>> &fld, Position start, Position end) {
    vector<vector<int>> dist(fld.size(), vector<int>(fld[0].size(), -1));
    vector<vector<int>> used(fld.size(), vector<int>(fld[0].size(), 0));
    int t = 1, t1 = 1;
    dist[start.x][start.y] = 1;
    dist[end.x][end.y] = 0;
    deque<Position> q = {start, end};
    while (!q.empty()) {
        auto top = q.front();
        q.pop_front();
        if (used[top.x][top.y])
            continue;
        if (dist[top.x][top.y] == 1) t++;
        else t1++;
        used[top.x][top.y] = 1;
        for (auto delta : deltas) {
            auto newPos = top + delta;
            if (newPos.x < 0 || newPos.y < 0 || newPos.x >= fld.size() || newPos.y >= fld[0].size() ||
                fld[newPos.x][newPos.y] == -1)
                continue;
            dist[newPos.x][newPos.y] = dist[top.x][top.y];
            q.push_back(newPos);
        }
    }
    return {t, t1};
}

double getFunction(const vector<vector<int>> &fld) {
    Position enemyPos, playerPos;
    int player = 1;
    int enemy = 2;
    int n = (int) fld.size();
    int m = (int) fld[0].size();
    int walls = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (fld[i][j] == enemy)
                enemyPos = Position(i, j);
            if (fld[i][j] == player)
                playerPos = Position(i, j);
            if (fld[i][j] == -1)
                walls++;
        }
    }
    double score = 0;
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        Position toCheck = playerPos + deltas[i];
        if (toCheck.x < 0 || toCheck.y < 0 || toCheck.x >= n || toCheck.y >= m || fld[toCheck.x][toCheck.y] != 0)
            continue;
        cnt++;
    }
    if (cnt == 0)
        return -1e7 * WIN;
    cnt = 0;
    for (int i = 0; i < 4; i++) {
        Position toCheck = enemyPos + deltas[i];
        if (toCheck.x < 0 || toCheck.y < 0 || toCheck.x >= n || toCheck.y >= m || fld[toCheck.x][toCheck.y] != 0)
            continue;
        cnt++;
    }
    if (cnt == 0)
        return WIN;
    vector<vector<int>> colors(n, vector<int>(m, -1));
    vector<int> comps;
    int color = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (fld[i][j] == -1)
                continue;
            if (colors[i][j] == -1)
                comps.push_back(dfs(Position(i, j), fld, colors, color++));
        }
    if (comps[colors[enemyPos.x][enemyPos.y]] < comps[colors[playerPos.x][playerPos.y]])
        return WIN;
    if (comps[colors[enemyPos.x][enemyPos.y]] > comps[colors[playerPos.x][playerPos.y]])
        return -1e7 * WIN;

    vector<vector<int>> fld1(n + 2, vector<int>(m + 2, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fld1[i + 1][j + 1] = fld[i][j];
        }
    }
    auto distFromPlayer = bfs(fld, playerPos);
    int sum = 0;
    for (auto i : distFromPlayer)
        for (auto j : i)
            if (j < 1e9)
                sum += j;

    auto distFromEnemy = bfs(fld, enemyPos);
    int sum1 = 0;
    for (auto i : distFromEnemy)
        for (auto j : i)
            if (j < 1e9)
                sum1 += j;

    auto top = bfs1(fld, playerPos, enemyPos);
    double k = 0.8;
    return -k * (sum - sum1) + (1 - k) * (top.first - top.second);
}

double minimax(int depth, vector<vector<int>> field, int player) {
    if (depth == MAX_DEPTH) {
        return getFunction(field);
    }
    int n = (int) field.size();
    int m = (int) field[0].size();
    Position playerPos;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (field[i][j] == player)
                playerPos = Position(i, j);
    field[playerPos.x][playerPos.y] = -1;
    if (player == 1) {
        double score = -DBL_MAX;
        for (Position &pos : deltas) {
            Position toCheck = pos + playerPos;
            if (toCheck.x < 0 || toCheck.y < 0 || toCheck.x >= n || toCheck.y >= m ||
                field[toCheck.x][toCheck.y] != 0)
                continue;
            field[toCheck.x][toCheck.y] = player;
            score = max(score, minimax(depth + 1, field, 3 - player));
            field[toCheck.x][toCheck.y] = 0;
        }
        return score;
    }

    double score = DBL_MAX;
    for (Position &pos : deltas) {
        Position toCheck = pos + playerPos;
        if (toCheck.x < 0 || toCheck.y < 0 || toCheck.x >= n || toCheck.y >= m || field[toCheck.x][toCheck.y] != 0)
            continue;
        field[toCheck.x][toCheck.y] = player;
        score = min(score, minimax(depth + 1, field, 3 - player));
        field[toCheck.x][toCheck.y] = 0;
    }
    return score;

}

Position calcNewTurn() {
    vector<vector<int>> preparedField(field.n, vector<int>(field.m));
    for (int i = 0; i < field.n; i++) {
        for (int j = 0; j < field.m; j++) {
            if (field[i][j] == ENEMY)
                preparedField[i][j] = 2;
            if (field[i][j] == PLAYER)
                preparedField[i][j] = -1;
            if (field[i][j] == WALL)
                preparedField[i][j] = -1;
            if (field[i][j] == FREE)
                preparedField[i][j] = 0;
        }
    }
    double score = -DBL_MAX;
    Position move = {-1, -1};
    for (Position pos : deltas) {
        Position possibleMove = player + pos;
        if (!field.isFree(possibleMove))
            continue;
        preparedField[possibleMove.x][possibleMove.y] = 1;
        double tmpScore = minimax(0, preparedField, 2);
        if (score < tmpScore || move.x == -1) {
            move = possibleMove;
            score = tmpScore;
        }
        preparedField[possibleMove.x][possibleMove.y] = 0;
    }
    cerr << "score is " << score << '\n';
    return move;
}


int main() {
    srand(time(0));
    while (true) {
        cin >> field;
        precalc();
        cout << calcNewTurn() << endl;
    }
}