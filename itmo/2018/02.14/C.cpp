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

int n;
struct Edge{
	int v, u, w;
	bool operator<(const Edge& oth) const {
		return tie(w, v, u) < tie(oth.w, oth.v, oth.u);
	}
};

vector<Edge> edges;
const int MAXN = 3e4;
int arr[MAXN];
int p[MAXN], sz[MAXN];

inline void init(){
	edges.clear();
}
int find_set(int a){
	if (p[a] == a)
		return a;
	return (p[a] = find_set(p[a]));
}
inline void un(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if (sz[a] > sz[b])
		swap(a, b);
	p[a] = b;
	sz[b] += sz[a];
}

inline void solve(){
	for (int i = 0; i < n; i++){
		cin >> arr[i];
		p[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i == j)
				continue;
			edges.push_back({i, j, arr[i] ^ arr[j]});
		}
	}
	int64_t ans = 0;
	sort(edges.rbegin(), edges.rend());
	for (int i = 0; i < edges.size(); i++){
		if (find_set(edges[i].v) != find_set(edges[i].u)){
			// cerr << edges[i].v << ' ' << edges[i].u << ' ' << edges[i].w << '\n';
			un(edges[i].v, edges[i].u);
			ans += edges[i].w;
		}
	}
	cout << ans << '\n';
}


int main(){
	#ifdef LOCAL
		freopen("C.in", "r", stdin);
		freopen("C.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n)
        solve();

}