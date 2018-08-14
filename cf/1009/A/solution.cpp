#include <bits/stdc++.h>

using namespace std;
void print(ostream& ot){
    ot << '\n';
}
template<typename Arg, typename... Args>
void print(ostream& ot, const Arg& arg, const Args&... arg1){
    ot << arg << ' ';
    print(ot, arg1...);
}


#define err(x) print(cerr, #x, x)

#ifdef LOCAL
const int INF = 100;
const int MAXN = 10;
#else
#define err() ;

const int INF = 1e9; 
const int MAXN = 1001;
#endif

// -*-*-* All variables *-*-*-
int n, m;
int arr[MAXN], arr1[MAXN];
// -*-*-* All functions *-*-*-
void init(){
    fill(arr, arr + n, 0);
    fill(arr1, arr1 + m, 0);
}

void solve(){
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < m; i++) cin >> arr1[i];
    int ans = 0;
    int r = 0;
    for (int i = 0; i < n; i++){
        if (r < m && arr[i] <= arr1[r]){
            ans++;
            r++;
        }
    }
    cout << ans << '\n';
}
int main(){
    #ifdef LOCAL
    clock_t start = clock();
    #endif
    cin >> n >> m;
    solve();
    #ifdef LOCAL
    cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
    #endif
}