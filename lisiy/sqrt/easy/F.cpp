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
const int MAXN = 12;
#else
#define err() ;
const int MAXN = 2e5;
const int INF = 1e18; 
#endif

// -*-*-* All variables *-*-*-
int arr[MAXN];
int tmp[MAXN];
const int block = 256;
int unsorted[block];
int pointer = 0, pointer1 = 0;
int m;

// -*-*-* All functions *-*-*-
void merge(){
    memset(tmp, 0, sizeof(tmp));
    sort(unsorted, unsorted + block);
    merge(arr, arr + pointer1, unsorted, unsorted + block, tmp);
    pointer1 += pointer;

    pointer = 0;
    swap(arr, tmp);
}
void init(){
    memset(arr, 0, sizeof(arr));
    memset(unsorted, 0, sizeof(unsorted));
    memset(tmp, 0, sizeof(tmp));
    pointer = pointer1 = 0;

}
int bin_search(int k){
    int l = 0, r = pointer1;
    while (r - l > 1){
        int m = (l + r) / 2;
        int lw = m, rw = m;
        for (int i = 0; i < pointer; i++){
            rw += (unsorted[i] <= arr[m]);
            lw += (unsorted[i] < arr[m]);
        }
        if (lw <= k && k <= rw) return arr[m];
        if (k < lw) l = m;
        else r = m;
    }
    return arr[m];
}
void solve(){
    while (m--){
        int type, x;
        cin >> type >> x;
        if (type == 1){
            unsorted[pointer++] = x;
            if (pointer == block) merge();
        }
        else{
            cout << bin_search(x - 1) << '\n';
        }
    }
}
int main(){
    #ifdef LOCAL
    string taskName = "F";
    freopen((taskName + ".in").c_str(), "r", stdin);
    freopen((taskName + ".out").c_str(), "w", stdout);
    clock_t start = clock();
    #else
    string taskName = "";
    // freopen((taskName + ".in").c_str(), "r", stdin);
    // freopen((taskName + ".out").c_str(), "w", stdout);
    #endif
    while(cin >> m){
        solve();
        #ifdef LOCAL
        cerr << "Elapsed " << setprecision(4) << fixed << (clock() - start * 1.) / CLOCKS_PER_SEC << '\n';
        #endif
    }
}