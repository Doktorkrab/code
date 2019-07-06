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
const int MAXN = 5e3;
int n, k;
pair<int, int> arr[MAXN];
int ans[MAXN];
vector<int> block_cnt[MAXN];
inline void init(){
	memset(arr, 0, sizeof(int) * MAXN);
	memset(ans, 0, sizeof(int) * MAXN);
	fill(block_cnt, block_cnt + MAXN, vector<int>());
}

inline void solve(){
	init();
	for (int i = 0; i < n; i++){
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr, arr + n);
	int block = 0;
	vector<int> empty;
	for (int i = 0; i < k; i++){
		empty.push_back(i);
	}
	for (int i = 0; i < n; i++){
		if (i > 0 && arr[i].first != arr[i - 1].first){
			if (block > k){
				cout << "NO\n";
				return;
			}
			block = 0;
		}
		block++;
		if (empty.size()){
			ans[arr[i].second] = empty.back();
			empty.pop_back();
			continue;
		}
		unordered_set<int> to_choice;
		for (int i = 0; i < k; i++)
			to_choice.insert(i);
		for (int j = i - 1; j >= 0 && arr[i].first == arr[j].first; j--){
			to_choice.erase(ans[arr[j].second]);
		}
		if (!to_choice.size()){
			cout << "NO\n";
			return;
		}
		ans[arr[i].second] = *to_choice.begin();
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++){
		cout << ans[i] + 1 << ' ';
	}
	cout << '\n';
	

}


int main(){
	#ifdef LOCAL
		freopen("B.in", "r", stdin);
		freopen("B.out", "w", stdout);
	#endif
	
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> k)
        solve();

}