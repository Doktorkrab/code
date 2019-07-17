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
vector<int> known, now, ans;
vector<pair<int, int>> inputs;

inline void init(){
    known.resize(n + m, -1);
    now.resize(n + m, -1);
    inputs.resize(n + m, {-1, -1});
    ans.resize(n + m, -1);
}

inline void solve(){
    init();
    for (int i = 0; i < m; i++){
        char c;
        cin >> c;
        if (c == '0')
            known[i + n] = now[i + n] = 0;
        else if (c == '1')
            known[i + n] = now[i + n] = 1;
        else
            known[i + n] = now[i + n] = -1;
    }
    for (int i = 0; i < m; i++){
        char c;
        cin >>c;
        int x;
        cin >> x;
        --x;
        if (c == 'c')
            x += n;
        char c1;
        int x1;
        cin >> c1 >> x1;
        --x1;
        if (c1 == 'c')
            x1 += n;
        inputs[i + n] = {x, x1};
    }
    for (int i = n + m - 1; i >= n; i--)
        if (known[i] == 0)
            known[inputs[i].first] = known[inputs[i].second] = 0;

    for (int i = n; i < n + m; i++)
        if (known[inputs[i].first] == 0 && known[inputs[i].second] == 0)
            known[i] = 0;
    ans = known;

    // for (int i = 0; i < n + m; i++)
    //     if (known[i] == -1)
    //         cerr << '?';
    //     else
    //         cerr << (char)(known[i] + '0');
    // cerr << '\n';
    for (int i = n; i < n + m; i++){
        if (ans[i] != -1)
            continue;
        now = known;
        now[i] = 0;
        int good = 1;
        for (int j = n + m - 1; j >= n; j--){
            if (now[j] == -1)
                continue;
            if (now[j] == 0){
                if (now[inputs[j].first] == 1 || now[inputs[j].second] == 1){
                    good = 0;
                    break;
                }
                now[inputs[j].first] = now[inputs[j].second] = 0; 
            }
        }
        for (int j = n; j < n + m; j++){
            // int ch = -1;
            int gg = now[inputs[j].first], hh = now[inputs[j].second];
            if ((gg == 1 || hh == 1) && now[j] == -1)
                now[j] = 1;
            if ((gg == 0 && hh == 0) && now[j] == -1)
                now[j] = 0;
            if (gg == 1 || hh == 1)
                good &= now[j] == 1;
            // cerr << j << ' ' << gg << ' '<< hh << ' ' << now[j] << '\n';
            if (gg == 0 && hh == 0)
                good &= now[j] == 0;
        }
        // for (int i = 0; i < n + m; i++)
        //     if (now[i] == -1)
        //         cerr << '?';
        //     else
        //         cerr << (char)(now[i] + '0');
        // cerr << '\n';
        if (good)
            ans[i] = -1;
        else
            ans[i] = 1;
    }
    
    for (int i = n; i < n + m; i++)
        if (ans[i] == -1)
            cout << '?';
        else
            cout << (char)(ans[i] + '0');
    cout << '\n';
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