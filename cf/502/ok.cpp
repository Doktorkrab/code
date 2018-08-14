#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

using namespace std;


int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	iota(arr.begin(), arr.end(), 1);
	reverse(arr.begin(), arr.end());
	vector<int> ans(n);
	set<vector<int>> gg;
	int ans_v = 1e9;
	do{
		vector<int> dp(n, 1), dp1(n, 1);
		int mx = 0, mx1 = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < i; j++){
				if (arr[j] < arr[i]){
					dp[i] = max(dp[i], dp[j] + 1);
					mx = max(dp[i], mx);
				}
				else{
					dp1[i] = max(dp1[i], dp1[j] + 1);
					mx1 = max(dp1[i], mx1);
				}
			}
		}
		if (ans_v > mx + mx1){
			ans_v = mx + mx1;
			ans = arr;
		}
		cout << ans_v << '\n';
		if (mx + mx1 < n / 2 + 2){
			for (int i = 0; i < n; i++) cout << arr[i] << ' ';
			cout << '\n'; 
		}
		gg.insert(arr);
		while (gg.count(arr)) random_shuffle(arr.begin(), arr.end());
	}while (1);
	// } while (prev_permutation(arr.begin(), arr.end()));
	cout << ans.size() << '\n';
	cout << ans_v << '\n';
		for (int i = 0; i < n; i++) cout << ans[i] << ' ';
		cout << '\n'; 
}