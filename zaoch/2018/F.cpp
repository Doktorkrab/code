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

const int MAXN = 1e6 + 7;
#define int uint64_t
int n;
int a[MAXN];
int b[MAXN];
int used[MAXN];
int kost[MAXN];

vector<int> gcd(int a, int b){
	if (b == 0)
		return {a, 1, 0};
	auto ret = gcd(b, a % b);
	return {ret[0], ret[2], ret[1] - ret[2] * (a / b)};
}
int crt(int a, int b, int n, int m){
	auto ret = gcd(n, m);
	int g = ret[0], x = ret[1], y = ret[2];
	if (a % g != b % g)
		return -1;
	return ((b * x * n / g) + a * m * y / g + n * m / g) % (n * m / g);
}
inline void init(){
	memset(a, 0, sizeof(int) * MAXN);
	memset(b, 0, sizeof(int) * MAXN);
	memset(kost, -1, sizeof(int) * MAXN);
	memset(used, 0, sizeof(int) * MAXN);
}

inline void solve(){
	init();
	for (int i = 0; i < n; i++){
		cin >> a[i];
		a[i]--;
	}
	
	for (int i = 0; i < n; i++){
		cin >> b[i];
		b[i]--;
	}
	vector<pair<int, int>> kto;
	for (int i = 0; i < n; i++){
		if (used[i])
			continue;

		int now = i;
		int cnt = 1;
		while (!used[now] && a[now] != b[i]){
			used[now] = 1;
			now = a[now];
			cnt++;
		}
		if (a[now] != b[i]){
			cout << "No\n";
			return;
		}
		int now1 = i;
		int cnt1 = 0;
		while (used[now] != 2 && a[now] == b[now1]){
			used[now] = 2;
			now = a[now];
			now1 = a[now1];
			cnt1++;
		}
		if (a[now] != b[now1]){
			cout << "No\n";
			return;
		}
		if (kost[cnt1] != -1 && kost[cnt1] != cnt){
			cout << "No\n";
			return;
		}
		if (kost[cnt1] != -1)
			continue;
		kost[cnt1] = cnt;
		kto.push_back({cnt % cnt1, cnt1});
	}
	if (kto.size() == 1){
		cout << "Yes\n";
		return;
	}
	// for (int i = 0; i < kto.size(); i++)
	// 	cout << kto[i].first << ' ' << kto[i].second << '\n';
	for (int i = 0; i < kto.size(); i++){
		for (int j = i + 1; j < kto.size(); j++){
			int ans = crt(kto[i].first, kto[j].first, kto[i].second, kto[j].second);
			if (ans == -1){
				cout << "No\n";
				return;
			}
		}
	}
	cout << "Yes\n";
}


int32_t main(){
	#ifdef LOCAL
		freopen("F.in", "r", stdin);
		freopen("F.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}