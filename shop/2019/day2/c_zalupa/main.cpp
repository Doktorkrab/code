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

struct Edge {
    int to, id;
};

int l, r, m;

int FAKE_LEFT, FAKE_RIGHT;


void solve() {
    vector<Edge> edges(m);
    vector<int> g1(l), g2(r);

}


int main() {
#ifdef LOCAL
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> l >> r >> m)
        solve();

}