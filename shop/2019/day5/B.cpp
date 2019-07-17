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
int n, m;
vector<string> arr;
vector<vector<uint64_t>> hsh;
vector<uint64_t> bases;
const int BASE = 239;
inline void init(){
    arr.resize(n);
    hsh.resize(n);
}
uint64_t get_hash(const vector<uint64_t>& hsh, int l, int r){
        // cerr << "!" << l << ' ' << r << ' ' << hsh.size() << '\n';
        // cerr << "!" << hsh[l] << ' ' << hsh[r] << ' ' << bases[r - l] << ' ' << hsh[l] * bases[r - l] << '\n';
        // cerr << "!" << hsh[r] - hsh[l] * bases[r - l] << '\n';
        return (uint64_t)(hsh[r] - hsh[l] * bases[r - l]);
}
inline void solve(){
    init();
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        hsh[i].resize(arr[i].size() + 1);
        if (bases.size() < arr[i].size() + 1)
            bases.resize(arr[i].size() + 1);
        bases[0] = 1;
        // cerr << hsh[i][0] << ' '; 
        for (int j = 0; j < (int)arr[i].size(); j++){
            bases[j + 1] = bases[j] * BASE;
            hsh[i][j + 1] = hsh[i][j] * BASE + arr[i][j];
            // cerr << hsh[i][j + 1] << ' ';
        }
        // cerr << '\n';

    }
    // for (int i = 0; i < 4; i++)
    //     cerr << bases[i] << " \n"[i == 3];
    // cerr << n << ' ' << m << '\n';
    for (int i = 0; i < m; i++){
        string p, q;
        cin >> p >> q;
        uint64_t hsh1 = 0, hsh2 = 0;
        for (char c : p)
            hsh1 = hsh1 * BASE + c;
        for (char c : q)
            hsh2 = hsh2 * BASE + c;
        int cnt = 0;
        for (int j = 0; j < n; j++){
            // cerr << i << ' ' << j << '\n';
            // cerr << hsh.size() << ' ' << arr.size() << '\n';
            string& s = arr[j];
            if (s.size() < p.size() || s.size() < q.size())
                continue;
            // cerr << s << ' ' << p << ' ' << q << '\n';
            // cerr << '\t' << (uint64_t)get_hash(hsh[j], 0, p.size()) << ' ' << hsh1 << '\n';
            // cerr << '\t' << get_hash(hsh[j], arr[j].size() - q.size(), arr[j].size()) << ' ' << hsh2 << '\n';
            cnt += ((get_hash(hsh[j], 0, p.size()) == hsh1) &&(get_hash(hsh[j], arr[j].size() - q.size(), arr[j].size()) == hsh2));
        }
        cout << cnt << '\n';
    }
}


int main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
        solve();

}