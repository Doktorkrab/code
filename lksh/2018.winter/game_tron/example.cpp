#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;

using std::pair;
using std::make_pair;


#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

pair<int, int> get_move(int n, int m, const vector<string>& field) {
    int px = -1, py = -1;

    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
            if (field[i][j] == '+')
                px = i, py = j;

    int dx[4] = {-1, +1, 0, 0};
    int dy[4] = {0, 0, +1, -1};

    for (int t = 0; t < 4; ++t)
        if (0 <= px + dx[t] and px + dx[t] < n and 0 <= py + dy[t] and py + dy[t] < m and field[px + dx[t]][py + dy[t]] == '.')
            return make_pair(px + dx[t], py + dy[t]);
        
    assert(false);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    while (true) {
        int n, m;
        cin >> n >> m;

        vector<string> field(n);
        for (int i = 0; i != n; ++i)
            cin >> field[i];
        
        pair<int, int> move = get_move(n, m, field);
        cout << move.first << " " << move.second << std::endl;
    }
    
    return 0;
}
