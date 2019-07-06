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
#include <climits>
using namespace std;
using ld = long double;
#define double ld
string l, r;
int n;
double logs[10];
inline void init(){
	logs[0] = 0;
	// cerr << logs[0] << ' ';
	for (int i = 1; i < 10; i++){
		logs[i] = log2(i);
		// cerr << logs[i] << ' ';
	}
	// cerr << '\n';
	reverse(l.begin(), l.end());
	while (l.size() < r.size()) l += '0';
	reverse(l.begin(), l.end());

	n = l.size();
}

inline void solve(){
	init();
	int lcp = 0;
	double prefix = 0;
	for (; lcp < n && l[lcp] == r[lcp]; lcp++) {
		if (l[lcp] == '0'){
			cout << l << '\n';
			return;
		}
		prefix += logs[l[lcp] - '0'];
	}
	double ansLeft = -1e18;
	int pos = n;
	double prefixR = prefix;
	int i;
	bool wasNotZeroes = 0;
	// cerr << lcp << ' ' << prefix << '\n';
	for (i = 0; i < lcp; i++)
		if (l[i] - '0' > 0)
			wasNotZeroes = 1;
	for (i = lcp; i < n; i++){
		if (r[i] - '1' < 0)
			break;
		if (r[i] - '1' == 0 && wasNotZeroes){
			if (l[i] - '0' == 0)
				break;
			prefix += logs[l[i] - '0'];
			continue;
		}
		if (l[i] - '0' > 0)
			wasNotZeroes = 1;
		double tmp = prefix + logs[r[i] - '1'] + (n - i - 1) * logs[9];
		if (tmp > ansLeft){
			ansLeft = tmp;
			pos = i;
		}
		if (l[i] - '0' == 0)
			break;
		// cerr << i << ' ' << l[i] - '0' << ' ' << logs[l[i] - '0'] << '\n';
		prefix += logs[l[i] - '0'];
	}
	double ansRight = -1e18;
	int pos1 = n;
	wasNotZeroes = 0;
	for (i = 0; i < lcp; i++)
		if (r[i] - '0' > 0)
			wasNotZeroes = 1;
	for (i = lcp; i < n; i++){
		if (r[i] - '1' < 0)
			break;
		if (r[i] - '1' == 0 && wasNotZeroes){
			prefixR += logs[r[i] - '0'];
			continue;
		}
		if (r[i] - '0' > 0)
			wasNotZeroes = 1;

		double tmp = prefixR + logs[r[i] - '1'] + (n - i - 1) * logs[9];
		if (tmp > ansRight){
			ansRight = tmp;
			pos1 = i;
		}
		prefixR += logs[r[i] - '0'];
	}
	if (prefixR > ansRight && i == n){
		ansRight = prefixR;
		pos1 = n;
	}
	// cerr << ansLeft << ' ' << ansRight << '\n';
	// cerr << pos << ' ' << pos1 << '\n';
	if (ansLeft > ansRight){
		for (i = 0; i < pos; i++){
			cout << l[i];
		}
		if (pos == n)
			return;
		cout << (char)(r[pos] - 1);
		for (i = pos + 1; i < n; i++)
			cout << 9;
		cout << '\n';
	}
	else {
		for (i = 0; i < pos1; i++){
			cout << r[i];
		}
		if (pos1 == n)
			return;
		cout << (char)(r[pos1] - 1);
		for (i = pos1 + 1; i < n; i++)
			cout << 9;
		cout << '\n';
	}
}


int main(){
	#ifdef LOCAL
		freopen("H.in", "r", stdin);
		freopen("H.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> l >> r)
        solve();

}