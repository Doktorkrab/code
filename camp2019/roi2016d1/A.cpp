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
#define cerr if (false) cerr
using namespace std;
#define int int64_t
const int MAXN = 1e5 + 7;
int n, s;
pair<int, int> arr[MAXN];
inline void init(){

}

inline void solve(){
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + n, [&](const pair<int, int> & a, const pair<int, int> &b){
        if (a.second != b.second)
            return a.second > b.second;
        return a.first > b.first;
    });
    int64_t ans = 0;
    multiset<int> ost;
    for (int i = 0; i < n; i++){
        if (ost.size())
        cerr << '?'<< *(ost.rbegin()) << ' ' << arr[i].second << '\n';
        while (s > 0 && ost.size() && arr[i].second <= arr[i].first && *(ost.rbegin()) > arr[i].second){
            ans -= *(ost.rbegin());
            cerr << "! " << *(ost.rbegin()) << '\n';
            ost.erase(prev(ost.end()));
            --s;
        }
        if (s > 0){
            int need = (arr[i].first) / arr[i].second;
            need = min(need, s);
            s -= need;
            cerr << arr[i].first << ' ' << arr[i].second << '\n';
            arr[i].first = max((int) 0, arr[i].first - need * arr[i].second);
            if (arr[i].first != 0)
                ost.insert(arr[i].first);
            cerr << need << ' ' << s << ' ' << arr[i].first << ' ' << ost.size() << '\n';
        }
        ans += arr[i].first;
    }
    while (s > 0 && ost.size()){
        ans -= *(ost.rbegin());
        cerr << "! " << *(ost.rbegin()) << '\n';
        ost.erase(prev(ost.end()));
        --s;
    }
    cout << ans << '\n';
}


int32_t main(){
	#ifdef LOCAL
		freopen("A.in", "r", stdin);
		freopen("A.out", "w", stdout);
        #else
                freopen("castle.in", "r", stdin);
                freopen("castle.out", "w", stdout);
        #endif
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> s)
        solve();

}
