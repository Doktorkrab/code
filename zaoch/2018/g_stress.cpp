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

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	vector<int> dp(n, 1);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++){
		for (int j = i - 1; j >= 0; j--){
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	int ans = 0;
	for (int i =0; i < n; i++){
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
}