#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const int INF = 100;
const int MAXN = 10;
#else
const int INF = 1e9; 
const int MAXN = 1e5;
#endif

struct Node{
    int sum;
};
// -*-*-* All variables *-*-*-
Node t[11][MAXN];
int n, N;

// -*-*-* All functions *-*-*-
void pull(int ind, int pos){
    t[ind][pos].sum = 0;
    if (2 * pos < 2 * N){
        t[ind][pos].sum += t[ind][2 * pos].sum;
    }
    if (2 * pos + 1 < 2 * N){
        t[ind][pos].sum += t[ind][2 * pos + 1].sum;
    }
}
void init(){
    int power = 0;
    while ((1 << power) < (n + 5)) power++;
    N = (1 << power);

    for (int i = 0;i < 11; i++){
        for (int j = 0; j < MAXN; j++){
            t[i][j] = {0};
        }
    }
}

int get(int ind, int pos, int tl, int tr, int l, int r){
    if (tl >= r || l >= tr) return 0;
    cerr << tl << ' ' << tr << ' ' << l << ' ' << r << ' ' << t[ind][pos].sum << '\n';
    if (l <= tl && tr <= r) return t[ind][pos].sum;
    int tm = (tl + tr) / 2;
    int ans = get(ind, 2 * pos, tl, tm, l, r) + get(ind, 2 * pos + 1, tm, tr, l, r);
    pull(ind, pos);
    return ans;
}

void update(int ind, int pos, int tl, int tr, int pos1, int x){
    if (pos1 < tl || pos1 >= tr) return;
    cerr << "       "<< pos << ' ' <<tl << ' ' << tr << ' ' << pos1 << ' ' << x << '\n';
    if (tr - tl == 1){
        t[ind][pos].sum = x;
        return;
    }
    int tm = (tl + tr) / 2;
    update(ind, 2 * pos, tl, tm, pos1, x);
    update(ind, 2 * pos + 1, tm, tr, pos1, x);
    pull(ind, pos);
    cerr << pos << ' ' << t[ind][pos].sum << '\n';
}

void solve(){
    init();
    cerr << N << '\n';
    int k;
    cin >> k;
    update(0, 1, 0, N, n + 1, 1);
    for (int i = 0;i < n; i++){
        int now;
        cin >> now;
        for (int j = 0; j < k; j++){
            cerr << get(j, 1, 0, N, now, n + 5) << '\n';
            update(j + 1, 1, 0, N, now, get(j, 1, 0, N, now, n + 5));
        }
    }
    cout << get(k, 1, 0, N, 0, n + 1) << '\n';
}
int main(){
    #ifdef LOCAL
    string taskName = "C";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    #else
    string taskName = "";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    #endif
    while(cin >> n){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}