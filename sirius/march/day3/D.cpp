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

int n, q;
const int MAXPOWER = 20;
const int MAXX = 1594324;
int triple[MAXPOWER];
int precalc[MAXX];
string toxic;

inline void init(){
	triple[0] = 1;
	for (int i = 1; i < MAXPOWER; i++)
		triple[i] = triple[i - 1] * 3;
}

inline void solve(){
	init();
	for (int mask = 0; mask < triple[n]; mask++){
		int have_2 = -1;
		for (int j = n - 1; j >= 0; j--){
			int tmp = mask / triple[j];
			if (tmp % 3 == 2){
				have_2 = j;
				break;
			}
		}
		if (have_2 != -1){
			// cerr << "\t" << mask << ' ' << mask - triple[have_2] << ' ' << mask - 2 * triple[have_2] << '\n';
			// cerr << "\t" << precalc[mask - triple[have_2]] << ' ' << precalc[mask - 2 * triple[have_2]] << '\n';
			precalc[mask] = precalc[mask - triple[have_2]] + precalc[mask - 2 * triple[have_2]];
			// cerr << "\t" << precalc[mask] << '\n'; 
			continue;
		}
		string decimal;
		int tmp = mask;
		do{
			decimal += '0' + (tmp % 3);
			tmp /= 3;
		} while(tmp > 0);
		reverse(decimal.begin(), decimal.end());
		int tmp1 = 0;
		for (char c : decimal){
			tmp1 = tmp1 * 2 + c - '0';
		}

		// cerr << tmp1 << ' ' << mask << ' ' << toxic[tmp1] << '\n';
		precalc[mask] = toxic[tmp1] - '0';
	}
	for (int i = 0; i < q; i++){
		int x;
		cin >> x;
		vector<int> gg(n);
		for (int j = 0; j < n; j++){
			gg[j] = x % 3;
			x /= 3;
		}
		// for (int i : gg)
		// 	cerr << i;
		// cerr << '\n';
		int mask = 0;
		for (int i = 0; i < n; i++)
			mask = mask * 3 + gg[i];
		// cerr << mask << '\n';
		cout << precalc[mask] << '\n';
	}
}


int main(){
	#ifdef LOCAL
		freopen("D.in", "r", stdin);
		freopen("D.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> q >> toxic)
        solve();

}