#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>

using namespace std;

const int OPEN = -1, CLOSE = 1;
struct Event{
    int type, ind;
    bool operator<(const Event& oth) const {
        return tie(type, ind) < tie(oth.type, oth.ind);
    }
};
const int MAXN = 2e5 + 7;
int people[MAXN];
int taken[MAXN];
map<int, vector<Event>> scanline;
set<pair<int, int>> waiting;

int n, c, k;

inline void init(){
    scanline.clear();
    memset(people, 0, sizeof(int) * MAXN);
    memset(taken, 0, sizeof(int) * MAXN);
    waiting.clear();
}

inline void solve(){
    init();
    for (int i = 0; i < n; i++){
        cin >> people[i];
        scanline[people[i]].push_back({OPEN, i});
        scanline[people[i] + k].push_back({CLOSE, i});
    }

    int ans = 0;
    for (const auto& [x, events] : scanline){
        for (auto & e : events){
            if (e.type == OPEN)
                waiting.insert({people[e.ind], e.ind});
            // cerr << e.ind << ' ' << people[e.ind] << ' ' << e.type << '\n';
        }
        // cerr << x << ' ' << waiting.size() << '\n';
        // cerr << waiting.begin()->first + k << '\n';
        while (waiting.size() && waiting.begin()->first + k == x){
            ans++;
            int cnt = 0;
            while (waiting.size() && cnt < c){
                cnt++;
                // cerr << '\t' << waiting.begin()->first << ' ' << waiting.begin()->second << '\n';
                waiting.erase(waiting.begin());
            }
        }
    }
    cout << ans << '\n';
    // cerr << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> c >> k)
        solve();

}