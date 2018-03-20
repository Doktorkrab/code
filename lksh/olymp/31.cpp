#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<iomanip>
#include<utility>
#include<algorithm>
#include<cmath>
#include<deque>
#include<queue>
using namespace std;

typedef long long int ll;

#define sz(x) ((long long int)(x).size())
#define pb push_back
#define pii pair<int, ll>
#define mp make_pair
#define y1 yyyyyyyy1

int main() {
	int n;
	long double d, t, eps = 1e-6;
	cin >> n >> t >> d;
	vector <long double> v(n);
	vector <long double> res;
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	res.pb(d / v[0]);
	//cout << res[0] << endl;
	for (int i = 1; i < n; ++i) {
		long double cnt = 0;
		for (int j = 0; j < i; ++j)
			cnt += t * v[j];
		if (d - 2.0L * cnt < 0)
			continue;
		if (t * i * 2.0L > res[0])
			continue;
		if (v[i] <= 0)
			continue;
		res.pb(t * i * 2.0L + (d - 2.0L * cnt) / v[i]);
		if ((d - 2.0L * cnt) / v[i] < t)
			res[sz(res) - 1] += t - ((d - 2.0L * cnt) / v[i]);
		//cout << res[i] << endl;
	}
	sort(res.begin(), res.end());
	cout << setprecision(20) << res[0];
	return 0;
}